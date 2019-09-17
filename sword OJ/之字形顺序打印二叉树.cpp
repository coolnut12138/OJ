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
        stack<TreeNode*> single;    //奇数层（左->右）
        stack<TreeNode*> even;      //偶数层（右->左）
        single.push(pRoot);
        TreeNode* tmp;
        while(!single.empty() || !even.empty()){
            vector<int> row;
            if(!single.empty()){
                while(!single.empty()){
                    tmp = single.top();
                    single.pop();
                    row.push_back(tmp->val);
                    if(tmp->left){
                        even.push(tmp->left);
                    }
                    if(tmp->right){
                        even.push(tmp->right);
                    }
                }
                ret.push_back(row);
            }
            if(!even.empty()){
                row.clear();
                while(!even.empty()){
                    tmp = even.top();
                    even.pop();
                    row.push_back(tmp->val);
                    if(tmp->right){
                        single.push(tmp->right);
                    }
                    if(tmp->left){
                        single.push(tmp->left);
                    }
                }
                ret.push_back(row);
            }
        }
        return ret;
    }
    
};