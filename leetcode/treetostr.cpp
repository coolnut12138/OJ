//leetcode 606.根据二叉树创建字符串
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
	string tree2str(TreeNode* t) {
		string ret = "";
		if (t == nullptr){
			return ret;
		}
		if (t->left == nullptr && t->right == nullptr){
			return ret.append(to_string(t->val));
		}

		ret.append(to_string(t->val));
		ret += ("(" + tree2str(t->left) + ")");
		if (t->right != nullptr)
			ret += ("(" + tree2str(t->right) + ")");

		return ret;
	}
};