//leetcode 102.�������Ĳ������
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
	int getHeight(TreeNode* root){
		if (root == nullptr){
			return 0;
		}

		int left = getHeight(root->left);
		int right = getHeight(root->right);
		return left > right ? left + 1 : right + 1;
	}
	vector<vector<int>> levelOrder(TreeNode* root) {
		//���������У�һ����Ž�㣬һ����Ų���
		queue<TreeNode*> pNode;
		queue<int> pIdx;
		vector<vector<int>> ret;
		ret.resize(getHeight(root));
		if (root){
			pNode.push(root);
			pIdx.push(0);
		}

		while (!pNode.empty()){
			//��ȡ��ǰ���׽��
			TreeNode *cur = pNode.front();
			pNode.pop();
			//��ȡ��ǰ����Ӧ�Ĳ㼶
			int idx = pIdx.front();
			pIdx.pop();
			//�ѽڵ�����Ӧ�Ĳ�,��Ϊ�����õ���[]����������Ҫ�ȸ�ret����ռ�
			ret[idx].push_back(cur->val);

			//�ѵ�ǰ�����ӽڵ������У��ӽڵ�Ĳ�ȸ��ڵ�Ĳ��1��
			if (cur->left){
				pNode.push(cur->left);
				pIdx.push(idx + 1);
			}
			if (cur->right){
				pNode.push(cur->right);
				pIdx.push(idx + 1);
			}
		}
		return ret;
	}
};

//leetcode 107.�������Ĳ������II
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
	int getHeight(TreeNode* root){
		if (root == nullptr){
			return 0;
		}

		int left = getHeight(root->left);
		int right = getHeight(root->right);
		return left > right ? left + 1 : right + 1;
	}
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		//˼·ͬ102�����洢���±�������ϴ漴�ɡ�
		queue<int> pIdx;
		queue<TreeNode*> pNode;
		vector<vector<int>> ret;
		int height = getHeight(root);
		ret.resize(height);
		if (root){
			pNode.push(root);
			pIdx.push(height - 1);
		}

		while (!pNode.empty()){
			TreeNode *curNode = pNode.front();
			pNode.pop();
			int idx = pIdx.front();
			pIdx.pop();
			ret[idx].push_back(curNode->val);

			if (curNode->left){
				pNode.push(curNode->left);
				pIdx.push(idx - 1);
			}
			if (curNode->right){
				pNode.push(curNode->right);
				pIdx.push(idx - 1);
			}
		}
		return ret;
	}
};

//leetcode 637.�������Ĳ�ƽ��ֵ
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
	vector<double> averageOfLevels(TreeNode* root) {
		queue<TreeNode*> pNode;
		vector<double> ave;

		if (root){
			pNode.push(root);
		}

		while (!pNode.empty()){
			//��¼ÿһ����ĸ���
			int len = pNode.size();
			double sum = 0;
			//ÿһ��Ľ���ֵ��ͣ�����ÿһ��Ľ������ҽ��ѹ�����
			for (int i = 0; i < len; i++){
				TreeNode *curNode = pNode.front();
				pNode.pop();
				sum += curNode->val;

				if (curNode->left){
					pNode.push(curNode->left);
				}
				if (curNode->right){
					pNode.push(curNode->right);
				}
			}
			//ÿһ����һ��ƽ��ֵ��ѹ�����
			ave.push_back(sum / len);
		}
		return ave;
	}
};

//leetcode 515.��ÿ�������������ֵ
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
	//˼·ͬleetcode 637. 
	vector<int> largestValues(TreeNode* root) {
		queue<TreeNode*> q;
		vector<int> maxVec;

		if (root){
			q.push(root);
		}

		while (!q.empty()){
			int len = q.size();
			int max = q.front()->val;
			//��ÿһ������ҵ����ֵ��Ȼ�����
			for (int i = 0; i < len; i++){
				TreeNode *curNode = q.front();
				q.pop();
				if (curNode->val > max){
					max = curNode->val;
				}

				if (curNode->left){
					q.push(curNode->left);
				}

				if (curNode->right){
					q.push(curNode->right);
				}
			}
			maxVec.push_back(max);
		}
		return maxVec;
	}
};