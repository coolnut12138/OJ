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
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> ret;
            if(pRoot == nullptr){
                return ret;
            }
            queue<TreeNode*> q;
            q.push(pRoot);
            while(!q.empty()){
                int num = 0;
                int size = q.size();
                vector<int> tmp;
                while(num++ < size){
                    TreeNode* node = q.front();
                    q.pop();
                    tmp.push_back(node->val);
                    if(node->left){
                        q.push(node->left);
                    }
                    if(node->right){
                        q.push(node->right);
                    }
                }
                ret.push_back(tmp);
            }
            return ret;
        }
};