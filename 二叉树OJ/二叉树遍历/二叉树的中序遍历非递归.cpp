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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> in;
		stack<TreeNode*> st;
		TreeNode *cur = root;
		while (cur || !st.empty()){
			//先找到最左边的结点
			while (cur){
				st.push(cur);
				cur = cur->left;
			}
			//然后左根右
			cur = st.top();
			st.pop();
			in.push_back(cur->val);
			cur = cur->right;
		}
		return in;
	}
};