链接：https://www.nowcoder.com/questionTerminal/81544a4989df4109b33c2d65037c5836?toCommentId=3247302
来源：牛客网
对字符串中的所有单词进行倒排。
说明：
1、每个单词是以26个大写或小写英文字母构成；
2、非构成单词的字符均视为单词间隔符；
3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；
4、每个单词最长20个字母；
//思路：先将整个字符串倒序，然后逐个单词倒序
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str)){
		//将字符串整体反转
		reverse(str.begin(), str.end());
		string tmp = "";
		int count = 0;    //空格标志位
		//将字符串中不是字母的字符替换为空格
		for (size_t i = 0; i < str.size(); ++i){
			if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z'){
				tmp += str[i];
				count = 0;
			}
			else{
				if (count == 0){    //空格数大于0就只要一个空格
					tmp += ' ';
				}
				count++;
			}
		}
		auto pos = tmp.begin();
		auto cur = tmp.begin();
		//反转每一个单词
		while (cur != tmp.end()){
			while (cur != tmp.end() && *cur != ' '){
				cur++;
			}
			reverse(pos, cur);
			if (cur != tmp.end()){
				cur++;
			}
			pos = cur;
		}

		//如果第一个字符是空格就删除第一个字符
		if (tmp[0] == ' '){
			tmp = tmp.substr(1);
		}
		//如果最后一个字符是空格就删除最后一个字符
		if (tmp[tmp.size() - 1] == ' '){
			tmp = tmp.substr(0, tmp.size() - 1);
		}
		cout << tmp << endl;
	}
	return 0;
}