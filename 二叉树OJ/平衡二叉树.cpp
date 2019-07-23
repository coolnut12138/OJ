给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/balanced-binary-tree。

class Solution {
public:
    int depth(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        
        return max(depth(root->left), depth(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        
        int left = depth(root->left) + 1;
        int right = depth(root->right) + 1;
        if(abs(left - right) > 1){
            return false;
        }
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
};