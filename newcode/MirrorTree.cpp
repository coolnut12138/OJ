//牛客：镜像二叉树，将二叉树镜像翻转
class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		queue<TreeNode*> q;
		if (pRoot){
			q.push(pRoot);
		}
		//将二叉树的结点都压入队列，然后对每个结点的左右结点做交换。
		while (!q.empty()){
			TreeNode* cur = q.front();
			q.pop();
			swap(cur->left, cur->right);
			if (cur->left){
				q.push(cur->left);
			}
			if (cur->right){
				q.push(cur->right);
			}
		}
	}
};