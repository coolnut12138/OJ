class Solution {
public:
    void _inorder(TreeNode* root, vector<int>& in){
        if(root == nullptr){
            return;
        }
        _inorder(root->left, in);
        in.push_back(root->val);
        _inorder(root->right, in);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> in;
        _inorder(root, in);
        return in;
    }
};