题目描述
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
class Solution {
public:
    int Depth(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        return max(Depth(root->left), Depth(root->right)) + 1;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == nullptr){
            return true;
        }
        
        int left = Depth(pRoot->left)+1;
        int right = Depth(pRoot->right)+1;
        if(abs(left-right) > 1){
            return false;
        }
        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
};