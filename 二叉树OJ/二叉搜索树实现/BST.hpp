#include <iostream>
using namespace std;

template<class T>
struct BSTNode
{
	BSTNode(const T& data = T())
		:_pLeft(nullptr)
		,_pRight(nullptr)
		,_data(data)
	{}
	BSTNode<T>* _pLeft;
	BSTNode<T>* _pRight;
	T _data;
};

template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
	typedef Node* PNode;
public:
	BSTree()
	{
		_root = nullptr;
	}

	PNode Find(const T& val) {
		if (_root == nullptr) {
			return nullptr;
		}
		PNode cur = _root;
		while (cur) {
			if (cur->_data == val) {
				cout << "find the node" << endl;
				return cur;
			}
			else if (cur->_data < val) {
				cur = cur->_pRight;
			}
			else {
				cur = cur->_pLeft;
			}
		}
		cout << "not found" << endl;
		return nullptr;
	}

	bool Insert(const T& val)
	{
		if (_root == nullptr) {
			_root = new Node(val);
			cout << "tree is nullptr,and Insert success" << endl;
			return true;
		}

		PNode parent = nullptr;
		PNode cur = _root;
		while (cur) {
			parent = cur;
			if (cur->_data < val) {
				cur = cur->_pRight;
			}
			else if (cur->_data > val) {
				cur = cur->_pLeft;
			}
			else
			{
				return false;
			}
		}

		if (val < parent->_data) {
			parent->_pLeft = new Node(val);
		}
		else if (val > parent->_data) {
			parent->_pRight = new Node(val);
		}
		cout << val << "Insert success" << endl;
		return true;
		
	}

	bool Erase(const T& val)
	{
		if (_root == nullptr) {
			cout << "tree is nullptr" << endl;
			return false;
		}

		PNode parent = nullptr;
		PNode cur = _root;
		//找到待删除的结点
		while (cur) {
			if (cur->_data > val) {
				parent = cur;
				cur = cur->_pLeft;
			}
			else if (cur->_data < val) {
				parent = cur;
				cur = cur->_pRight;
			}
			else {
				break;
			}
		}

		if (cur == nullptr) {
			cout << "Node not exist" << endl;
			return false;
		}

		if (cur->_pLeft == nullptr && cur->_pRight == nullptr) {
			if (cur == _root) {
				_root = nullptr;
			}
			else {
				if (parent->_pLeft == cur) {
					parent->_pLeft = nullptr;
				}
				else if(parent->_pRight == cur){
					parent->_pRight = nullptr;
				}
			}
			delete cur;
			cur = nullptr;
		}
		else if (cur->_pLeft == nullptr) {
			//只有右孩子，或者没有孩子
			if (cur != nullptr) {
				if (parent->_pLeft == cur) {
					parent->_pLeft = cur->_pRight;
				}
				else if (parent->_pRight == cur) {
					parent->_pRight = cur->_pRight;
				}
			}
			else {
				_root = cur->_pRight;
			}
			delete cur;
			cur = nullptr;
		}
		else if (cur->_pRight == nullptr) {
			//只有左孩子
			if (cur != _root) {
				if (parent->_pLeft = cur) {
					parent->_pLeft = cur->_pLeft;
				}
				else if (parent->_pRight = cur) {
					parent->_pRight = cur->_pLeft;
				}
			}
			else {
				_root = cur->_pLeft;
			}
			delete cur;
			cur = nullptr;
		}
		else {
			//左右孩子都有，找左子树的最大孩子结点或者右子树的最小孩子结点与之替换，然后删除即可
			PNode leftMost = cur->_pLeft;
			parent = cur;
			while (leftMost->_pRight) {
				parent = leftMost;
				leftMost = leftMost->_pRight;
			}

			cur->_data = leftMost->_data;
			if (parent->_pLeft == leftMost) {
				parent->_pLeft = leftMost->_pLeft;
			}
			else if (parent->_pRight == leftMost) {
				parent->_pRight = leftMost->_pLeft;
			}
			delete leftMost;
			leftMost = nullptr;
		}
		return true;
	}

	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}

	void Root()
	{
		cout << "root is:" << " ";
		cout << _root->_data << endl;
	}

	~BSTree()
	{
		Destroy(_root);
	}
private:
	PNode _root;
private:
	void Destroy(PNode root) {
		if (root != nullptr) {
			Destroy(root->_pLeft);
			Destroy(root->_pRight);
			delete root;
			root = nullptr;
		}
	}

	void _Inorder(PNode root) {
		if (root == nullptr) {
			return;
		}
		_Inorder(root->_pLeft);
		cout << root->_data << " ";
		_Inorder(root->_pRight);
	}
};