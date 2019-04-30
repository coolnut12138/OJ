//leetcode 102.二叉树的层序遍历
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	int getHeight(TreeNode* root){
		if (root == nullptr){
			return 0;
		}

		int left = getHeight(root->left);
		int right = getHeight(root->right);
		return left > right ? left + 1 : right + 1;
	}
	vector<vector<int>> levelOrder(TreeNode* root) {
		//搞两个队列，一个存放结点，一个存放层数
		queue<TreeNode*> pNode;
		queue<int> pIdx;
		vector<vector<int>> ret;
		ret.resize(getHeight(root));
		if (root){
			pNode.push(root);
			pIdx.push(0);
		}

		while (!pNode.empty()){
			//获取当前队首结点
			TreeNode *cur = pNode.front();
			pNode.pop();
			//获取当前结点对应的层级
			int idx = pIdx.front();
			pIdx.pop();
			//把节点存入对应的层,因为这里用到了[]操作，所以要先给ret分配空间
			ret[idx].push_back(cur->val);

			//把当前结点的子节点存入队列，子节点的层比父节点的层大1；
			if (cur->left){
				pNode.push(cur->left);
				pIdx.push(idx + 1);
			}
			if (cur->right){
				pNode.push(cur->right);
				pIdx.push(idx + 1);
			}
		}
		return ret;
	}
};

//leetcode 107.二叉树的层序遍历II
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	int getHeight(TreeNode* root){
		if (root == nullptr){
			return 0;
		}

		int left = getHeight(root->left);
		int right = getHeight(root->right);
		return left > right ? left + 1 : right + 1;
	}
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		//思路同102，将存储的下标从下往上存即可。
		queue<int> pIdx;
		queue<TreeNode*> pNode;
		vector<vector<int>> ret;
		int height = getHeight(root);
		ret.resize(height);
		if (root){
			pNode.push(root);
			pIdx.push(height - 1);
		}

		while (!pNode.empty()){
			TreeNode *curNode = pNode.front();
			pNode.pop();
			int idx = pIdx.front();
			pIdx.pop();
			ret[idx].push_back(curNode->val);

			if (curNode->left){
				pNode.push(curNode->left);
				pIdx.push(idx - 1);
			}
			if (curNode->right){
				pNode.push(curNode->right);
				pIdx.push(idx - 1);
			}
		}
		return ret;
	}
};

