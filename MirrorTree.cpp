//ţ�ͣ������������������������ת
class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		queue<TreeNode*> q;
		if (pRoot){
			q.push(pRoot);
		}
		//���������Ľ�㶼ѹ����У�Ȼ���ÿ���������ҽ����������
		while (!q.empty()){
			TreeNode* cur = q.front();
			q.pop();
			swap(cur->left, cur->right);
			if (cur->left){
				q.push(cur->left);
			}
			if (cur->right){
				q.push(cur->right);
			}
		}
	}
};