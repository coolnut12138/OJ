class Solution {
public:
    void _postorder(TreeNode* root, vector<int>& post){
        if(root == nullptr){
            return;
        }
        _postorder(root->left, post);
        _postorder(root->right, post);
        post.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> post;
        _postorder(root, post);
        return post;
    }
};