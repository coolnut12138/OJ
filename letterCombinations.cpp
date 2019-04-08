#define _CRT_SECURE_NO_WARNINGS 1
//leetcode17.�绰�������ĸ���
class Solution {
	char* numToStr[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
public:
	void combinations(const string& digits, size_t index, vector<string>& strV, const string& combineStr)
	{
		if (index == digits.size())      //��Ϊvector���൱���ַ������飬������"23"ʱ�����Ǹ��ݽ��������飬�ҵ���Ӧ�İ������ַ�������ô�ݹ����������������ײ�ʱ��Ҳ���ǵ��ַ�������������ʱֹͣ����ʱҲ�Ѿ������һ�ֶ�Ӧ��ĸ��ӳ�䣬����strV�У�Ȼ�󷵻���һ����á�
		{
			strV.push_back(combineStr);
			return;
		}
		int num = digits[index] - '0';      //����ǰ�������ַ����е���һλת��������
		string str = numToStr[num];         //��ǰ�������������ַ���
		for (auto ch : str)
		{
			combinations(digits, index + 1, strV, combineStr + ch);//������+����+=����Ϊ���ܰѴ��������ַ����ı��ˡ�
		}
	}
	vector<string> letterCombinations(string digits) {
		if (digits.empty()){ //��������մ������
			return vector<string>();    //������������
		}
		vector<string> strV;    //������ս��
		size_t index = 0;
		string combineStr;      //���ÿ��С���ݹ���ַ���
		combinations(digits, index, strV, combineStr);

		return strV;
	}
};