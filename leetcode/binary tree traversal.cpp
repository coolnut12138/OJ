//leetcode 144.二叉树的前序遍历
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
	void  __preorder(TreeNode* root, vector<int>& ret)
	{
		if (root == nullptr){
			return;
		}

		ret.push_back(root->val);
		__preorder(root->left, ret);
		__preorder(root->right, ret);
	}
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ret;
		__preorder(root, ret);
		return ret;
	}
};

//leetcode 94.二叉树的中序遍历
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
	void __inorder(TreeNode* root, vector<int>& ret)
	{
		if (root == nullptr){
			return;
		}

		__inorder(root->left, ret);
		ret.push_back(root->val);
		__inorder(root->right, ret);
	}
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ret;
		__inorder(root, ret);
		return ret;
	}
};

//leetcode145.二叉树的后序遍历
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
	void __postorder(TreeNode* root, vector<int>& ret)
	{
		if (root == nullptr){
			return;
		}

		__postorder(root->left, ret);
		__postorder(root->right, ret);
		ret.push_back(root->val);
	}
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ret;
		__postorder(root, ret);
		return ret;
	}
};