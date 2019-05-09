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
		//pRoot2遍历完了，就是包含pRoot2
		if (r2 == nullptr){
			return true;
		}
		//p1遍历完了，p2还没遍历完证明不包含
		if (r1 == nullptr){
			return false;
		}
		//如果结点不等就不包含
		if (r1->val != r2->val){
			return false;
		}
		//如果结点相等就判断左右子树
		return isSubtree(r1->left, r2->left)
			&& isSubtree(r1->right, r2->right);
	}
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool result = false;
		//结点值都不为空才判断
		if (pRoot1 != nullptr && pRoot2 != nullptr){
			//如果找到相等的结点就去这个结点下去找是否包含
			if (pRoot1->val == pRoot2->val){
				result = isSubtree(pRoot1, pRoot2);
			}
			//如果找不到就去pRoot1的左子树找
			if (!result){
				result = HasSubtree(pRoot1->left, pRoot2);
			}
			//还找不到就去pRoot1的右子树找
			if (!result){
				result = HasSubtree(pRoot1->right, pRoot2);
			}
		}
		return result;
	}
};