//leetcode145. �������ĺ������
//�ⷨһ��
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
			//�ȴӸ�������ߵĽ��ѹջ
			while (cur){
				st.push(cur);
				cur = cur->left;
			}
			//ȡ��ջ��Ԫ��
			auto top = st.top();
			//�ж��������ұ��Ƿ��н������ұߵĽ���Ƿ��Ѿ���������
			//����ҽ�㲻Ϊ����û�б�����������ȥ�����ҽ��
			//�������ұ�û�н�㣬�����ұߵĽ���Ѿ����������ˣ���ѵ�ǰ�������������������У�
			//Ȼ��ǰ����Ѿ����ڱ������ˣ����Ը���flagΪ��ǰ��㡣
			if (top->right == nullptr || top->right == pre){
				//���Ѿ���ӵ�Ԫ�ر���£�����ҽ��Ϊ�ջ����ҽ���Ѿ���������ӹ����ͽ���������
				pre = top;
				retVec.push_back(top->val);
				//�ǵ�Ҫ��cur�ÿգ���Ϊ�ߵ�����ʹ��������������������������
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
//�ⷨ����
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
		//�������ȡ�ɵ�������
		//����һ��αǰ��������������αǰ�������˳���Ǹ�����
		//Ȼ��תvector���ɵõ���������
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