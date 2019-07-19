class Solution {
public:
    void _preorder(TreeNode* root, vector<int>& ret){
        if(root == nullptr){
            return;
        }
        ret.push_back(root->val);
        _preorder(root->left, ret);
        _preorder(root->right, ret);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        _preorder(root, ret);
        return ret;
    }
};