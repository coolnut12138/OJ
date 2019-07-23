给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/symmetric-tree

class Solution {
public:
    bool isMirrorTree(TreeNode* left, TreeNode* right){
        if(left == nullptr && right == nullptr){
            return true;
        }
        if(left == nullptr || right == nullptr){
            return false;
        }
        
        return left->val == right->val
            && isMirrorTree(left->left, right->right)
            && isMirrorTree(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        
        return isMirrorTree(root->left, root->right);
    }
};