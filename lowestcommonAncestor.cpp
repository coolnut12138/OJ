//leetcode 236，两个结点最近的公共祖先
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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr || root == p || root == q)
			return root;

		TreeNode* leftN = lowestCommonAncestor(root->left, p, q);
		TreeNode* rightN = lowestCommonAncestor(root->right, p, q);

		if (leftN != nullptr && rightN != nullptr)
			return root;

		if (leftN == nullptr)
			return rightN;

		return leftN;
	}
};