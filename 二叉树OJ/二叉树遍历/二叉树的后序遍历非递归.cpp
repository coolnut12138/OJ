//leetcode145. 二叉树的后序遍历
//解法一、
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
	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> retVec;
		TreeNode *cur = root;
		TreeNode *pre = nullptr;
		while (!st.empty() || cur){
			//先从根到最左边的结点压栈
			while (cur){
				st.push(cur);
				cur = cur->left;
			}
			//取出栈顶元素
			auto top = st.top();
			//判断这个结点右边是否有结点或者右边的结点是否已经被遍历过
			//如果右结点不为空且没有遍历过，就先去遍历右结点
			//如果结点右边没有结点，或者右边的结点已经被遍历过了，则把当前结点放入后序遍历的数组中，
			//然后当前结点已经属于遍历过了，所以更新flag为当前结点。
			if (top->right == nullptr || top->right == pre){
				//将已经入队的元素标记下，如果右结点为空或者右结点已经遍历并入队过，就将本结点入队
				pre = top;
				retVec.push_back(top->val);
				//记得要将cur置空，因为走到这里就代表左右子树都被遍历并入队了
				cur = nullptr;
				st.pop();
			}
			else{
				cur = top->right;
			}
		}
		return retVec;
	}
};
//解法二、
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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> post;
		stack<TreeNode*> st;
		TreeNode *cur = root;
		//后序遍历取巧的做法：
		//先做一个伪前序遍历，不过这个伪前序遍历的顺序是根右左
		//然后反转vector即可得到后续遍历
		while (cur || !st.empty()){
			while (cur){
				st.push(cur);
				post.push_back(cur->val);
				cur = cur->right;
			}

			cur = st.top();
			st.pop();
			cur = cur->left;
		}
		reverse(post.begin(), post.end());
		return post;
	}
};