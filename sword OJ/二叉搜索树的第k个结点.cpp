题目描述
给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。

二叉搜索树的特性是根大于左子树，根小于右子树，
所以先中序遍历得到有序数组，再去拿到第k个结点即可
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<TreeNode*> Inorder(TreeNode* pRoot, int& count)
    {
        stack<TreeNode*> st;
        vector<TreeNode*> ret;
        TreeNode* cur = pRoot;
        while(cur || !st.empty()){
            while(cur){
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            ret.push_back(cur);
            count--;
            cur = cur->right;
        }
        return ret;
    }
    
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == nullptr || k < 1){
            return nullptr;
        }
        int count = k;
        vector<TreeNode*> ret = Inorder(pRoot, count);
        if(count <= 0){
            return ret[k - 1];
        }
        else{
            return nullptr;
        }
    }
};