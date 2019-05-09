/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	bool isSubtree(TreeNode* r1, TreeNode* r2){
		//pRoot2�������ˣ����ǰ���pRoot2
		if (r2 == nullptr){
			return true;
		}
		//p1�������ˣ�p2��û������֤��������
		if (r1 == nullptr){
			return false;
		}
		//�����㲻�ȾͲ�����
		if (r1->val != r2->val){
			return false;
		}
		//��������Ⱦ��ж���������
		return isSubtree(r1->left, r2->left)
			&& isSubtree(r1->right, r2->right);
	}
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool result = false;
		//���ֵ����Ϊ�ղ��ж�
		if (pRoot1 != nullptr && pRoot2 != nullptr){
			//����ҵ���ȵĽ���ȥ��������ȥ���Ƿ����
			if (pRoot1->val == pRoot2->val){
				result = isSubtree(pRoot1, pRoot2);
			}
			//����Ҳ�����ȥpRoot1����������
			if (!result){
				result = HasSubtree(pRoot1->left, pRoot2);
			}
			//���Ҳ�����ȥpRoot1����������
			if (!result){
				result = HasSubtree(pRoot1->right, pRoot2);
			}
		}
		return result;
	}
};