#define _CRT_SECURE_NO_WARNINGS 1
//leetcode17.电话号码的字母组合
class Solution {
	char* numToStr[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
public:
	void combinations(const string& digits, size_t index, vector<string>& strV, const string& combineStr)
	{
		if (index == digits.size())      //因为vector中相当是字符串数组，当输入"23"时，我们根据建立的数组，找到相应的按键的字符串，那么递归的跳出条件：到最底层时，也就是到字符串数组的最后面时停止，此时也已经完成了一轮对应字母的映射，放入strV中，然后返回上一层调用。
		{
			strV.push_back(combineStr);
			return;
		}
		int num = digits[index] - '0';      //将当前被调用字符串中的那一位转换成数字
		string str = numToStr[num];         //当前即将被遍历的字符串
		for (auto ch : str)
		{
			combinations(digits, index + 1, strV, combineStr + ch);//这里是+不是+=，因为不能把传进来的字符串改变了。
		}
	}
	vector<string> letterCombinations(string digits) {
		if (digits.empty()){ //考虑输入空串的情况
			return vector<string>();    //返回匿名对象
		}
		vector<string> strV;    //存放最终结果
		size_t index = 0;
		string combineStr;      //存放每次小步递归的字符串
		combinations(digits, index, strV, combineStr);

		return strV;
	}
};