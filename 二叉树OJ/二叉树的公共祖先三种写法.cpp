//leetcode236.二叉树的最近公共祖先
//解法一：
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	//找出结点路径存入栈中
	bool GetPath(TreeNode *root, TreeNode *node, stack<TreeNode*>& st){
		if (root == nullptr){
			return false;
		}

		st.push(root);
		if (root == node){
			return true;
		}

		if (GetPath(root->left, node, st)){
			return true;
		}
		if (GetPath(root->right, node, st)){
			return true;
		}

		st.pop();
		return false;
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		stack<TreeNode*> pathp;
		stack<TreeNode*> pathq;
		GetPath(root, p, pathp);
		GetPath(root, q, pathq);
		//裁剪路径，让两个路径一样长
		while (pathp.size() != pathq.size()){
			if (pathp.size() > pathq.size()){
				pathp.pop();
			}
			else{
				pathq.pop();
			}
		}
		//第一个结点相同即为祖先
		while (!pathp.empty()){
			if (pathp.top() == pathq.top()){
				break;
			}
			else{
				pathp.pop();
				pathq.pop();
			}
		}
		return pathp.top();
	}
};

//解法二：
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:

	bool contain(TreeNode* root, TreeNode* node){
		if (root == nullptr){
			return false;
		}
		if (root == node){
			return true;
		}

		if (contain(root->left, node) == true){
			return true;
		}

		return contain(root->right, node);
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//分别判断两个结点是不是在同一棵树中
		bool pInleft = contain(root->left, p);
		bool qInleft = contain(root->left, q);
		bool pInright = !pInleft && p != root;
		bool qInright = !qInleft && q != root;

		//两个结点都在左子树
		if (pInleft && qInleft){
			return lowestCommonAncestor(root->left, p, q);
		}
		//两个结点都在右子树
		if (pInright && qInright){
			return lowestCommonAncestor(root->right, p, q);
		}

		return root;
	}
};

//解法三：
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr || root == p || root == q)
			return root;
		TreeNode* leftN = lowestCommonAncestor(root->left, p, q);
		TreeNode* rightN = lowestCommonAncestor(root->right, p, q);
		if (leftN != nullptr && rightN != nullptr)
			return root;
		if (leftN == nullptr)
			return rightN;
		return leftN;
	}
};