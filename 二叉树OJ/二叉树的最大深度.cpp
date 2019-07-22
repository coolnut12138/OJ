给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree

//递归写法
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        return (left > right ? left : right) + 1;
    }
};

//非递归写法，层序遍历
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        
        int height = 0;
        queue<TreeNode*> que;
        que.push(root);
        TreeNode *cur = nullptr;
        TreeNode *lastNode = root;
        while(!que.empty()){
            cur = que.front();
            que.pop();
            
            if(cur->left){
                que.push(cur->left);
            }
            if(cur->right){
                que.push(cur->right);
            }
            
            if(lastNode == cur){
                height++;
                lastNode = que.back();
            }
        }
        return height;
    }
};