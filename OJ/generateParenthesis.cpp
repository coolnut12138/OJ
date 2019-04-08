#define _CRT_SECURE_NO_WARNINGS 1
//leetcode22.��������
class Solution {

public:
	void bracketCreate(string str, int left, int right, int maxleft, int maxright, vector<string>& ret)
	{
		//���������������17��绰������ĸ���
		if (left + right == maxleft + maxright)
		{
			ret.push_back(str);
			return;
		}

		if (left < maxleft)
		{
			bracketCreate(str + '(', left + 1, right, maxleft, maxright, ret);
		}
		if (right < left && right < maxright)
		{
			bracketCreate(str + ')', left, right + 1, maxleft, maxright, ret);
		}
	}
	//���뼸�������ɼ������ţ�Ҳ������n�������ź�n��������
	vector<string> generateParenthesis(int n) {
		if (n == 0)
		{
			return vector<string>();
		}
		vector<string> ret;
		int maxleft = n;
		int maxright = n;
		bracketCreate("", 0, 0, maxleft, maxright, ret);
		return ret;
	}
};