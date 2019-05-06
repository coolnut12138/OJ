leetcode�� N�����Ĳ������
/*
// Definition for a Node.
class Node {
public:
int val;
vector<Node*> children;

Node() {}

Node(int _val, vector<Node*> _children) {
val = _val;
children = _children;
}
};
*/
class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>> ret;
		//�߽���������������Ϊ�գ���ôֱ�ӷ��ؿ�vector
		if (!root){
			return ret;
		}
		queue<Node*> q;
		//�Է�չ���ߵķ�ʽ�ڶ����д洢��㣬�ȷ�ÿһ����㣬Ȼ���ٷ�ÿһ�����ĺ��ӽ��
		q.push(root);
		while (!q.empty()){
			//tmp���ÿһ�����ֵ�����磺�ڶ��㣺3 2 4
			vector<int> tmp;
			int n = q.size();
			//��ʱ���еĸ���������һ����ĸ�������ÿһ�����ĺ��ӽ����ӣ�
			for (int i = 0; i < n; i++){
				Node* cur = q.front();
				q.pop();
				tmp.push_back(cur->val);
				//children��һ��vector���͵ĳ�Ա���������Կ���ֱ�ӵ���children.size()����ȡ���ӽڵ�ĸ���
				for (int j = 0; j < cur->children.size(); j++){
					q.push(cur->children[j]);
				}
			}
			//ÿһ��Ľ��ֵ����vector<vector<int>>�С�
			ret.push_back(tmp);
		}
		return ret;
	}
};

���������ݹ鷽��
/*
// Definition for a Node.
class Node {
public:
int val;
vector<Node*> children;

Node() {}

Node(int _val, vector<Node*> _children) {
val = _val;
children = _children;
}
};
*/
class Solution {
public:
	int GetHeight(Node* root){
		if (root == nullptr){
			return 0;
		}

		int maxHeight = 0;
		for (auto it : root->children){
			maxHeight = max(maxHeight, GetHeight(it));
		}
		return maxHeight + 1;
	}

	void _levelOrder(Node* root, int level, vector<vector<int>> &ret){
		if (root == nullptr){
			return;
		}
		ret[level].push_back(root->val);
		for (auto it : root->children){
			_levelOrder(it, level + 1, ret);
		}
	}

	vector<vector<int>> levelOrder(Node* root) {
		int height = GetHeight(root);
		vector<vector<int>> ret(height);

		if (height == 0){
			return ret;
		}

		_levelOrder(root, 0, ret);
		return ret;
	}
};