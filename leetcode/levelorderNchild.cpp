leetcode。 N叉树的层序遍历
/*
// Definition for a Node.
class Node {
public:
int val;
vector<Node*> children;

Node() {}

Node(int _val, vector<Node*> _children) {
val = _val;
children = _children;
}
};
*/
class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>> ret;
		//边界条件，如果根结点为空，那么直接返回空vector
		if (!root){
			return ret;
		}
		queue<Node*> q;
		//以发展下线的方式在队列中存储结点，先放每一个结点，然后再放每一个结点的孩子结点
		q.push(root);
		while (!q.empty()){
			//tmp存放每一层结点的值，比如：第二层：3 2 4
			vector<int> tmp;
			int n = q.size();
			//此时队列的个数就是这一层结点的个数，将每一个结点的孩子结点入队，
			for (int i = 0; i < n; i++){
				Node* cur = q.front();
				q.pop();
				tmp.push_back(cur->val);
				//children是一个vector类型的成员变量，所以可以直接调用children.size()来获取孩子节点的个数
				for (int j = 0; j < cur->children.size(); j++){
					q.push(cur->children[j]);
				}
			}
			//每一层的结点值存入vector<vector<int>>中。
			ret.push_back(tmp);
		}
		return ret;
	}
};

方法二：递归方法
/*
// Definition for a Node.
class Node {
public:
int val;
vector<Node*> children;

Node() {}

Node(int _val, vector<Node*> _children) {
val = _val;
children = _children;
}
};
*/
class Solution {
public:
	int GetHeight(Node* root){
		if (root == nullptr){
			return 0;
		}

		int maxHeight = 0;
		for (auto it : root->children){
			maxHeight = max(maxHeight, GetHeight(it));
		}
		return maxHeight + 1;
	}

	void _levelOrder(Node* root, int level, vector<vector<int>> &ret){
		if (root == nullptr){
			return;
		}
		ret[level].push_back(root->val);
		for (auto it : root->children){
			_levelOrder(it, level + 1, ret);
		}
	}

	vector<vector<int>> levelOrder(Node* root) {
		int height = GetHeight(root);
		vector<vector<int>> ret(height);

		if (height == 0){
			return ret;
		}

		_levelOrder(root, 0, ret);
		return ret;
	}
};