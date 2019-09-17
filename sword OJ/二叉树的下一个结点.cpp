/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
//方法一：先找到根结点，写出中序遍历，找到下一个结点即可
class Solution {
public:
    void Inorder(TreeLinkNode* root, vector<TreeLinkNode*>& ret){
        if(root == nullptr){
            return;
        }
        Inorder(root->left, ret);
        ret.push_back(root);
        Inorder(root->right, ret);
    }
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        TreeLinkNode* cur = pNode;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        vector<TreeLinkNode*> ret;
        Inorder(cur, ret);
        for(int i = 0; i < ret.size(); i++){
            if(ret[i] == pNode){
                if(i == ret.size() - 1){
                    return nullptr;
                }
                else{
                    return ret[i + 1];
                }
            }
        }
    }
};


//方法二：
//当前结点有三种情况：
//情况一：空，返回空
//情况二：当前结点有右子树，下一个结点为右子树的最左孩子
//情况三：当前结点非根且自己不为父节点的左孩子，找到一个父节点，这个父节点的左孩子是自己，返回父节点
//		  (因为中序是左根右，当前结点是左孩子就证明它的根没有被访问)
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == nullptr){
            return nullptr;
        }
        if(pNode->right != nullptr){
            TreeLinkNode* cur = pNode->right;
            while(cur->left){
                cur = cur->left;
            }
            return cur;
        }
        while(pNode->next != nullptr){
            TreeLinkNode* parent = pNode->next;
            if(parent->left == pNode){
                return parent;
            }
            pNode = pNode->next;
        }
        return nullptr;
    }
};