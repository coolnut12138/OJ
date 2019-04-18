//leetcode 236�������������Ĺ�������
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

//��дһ�������ȽϺ����
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
	//�жϽ���Ƿ����������
	bool contains(TreeNode* root, TreeNode* node){
		if (root == nullptr){
			return false;
		}
		if (root == node){
			return true;
		}
		if (contains(root->left, node) == true){
			return true;
		}

		return contains(root->right, node);
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		bool pInleft = contains(root->left, p);
		bool qInleft = contains(root->left, q);
		bool pInright = !pInleft && p != root;
		bool qInright = !qInleft && q != root;

		if (pInleft && qInleft){
			return lowestCommonAncestor(root->left, p, q);
		}

		if (pInright && qInright){
			return lowestCommonAncestor(root->right, p, q);
		}

		return root;
	}
};