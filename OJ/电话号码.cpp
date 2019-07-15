链接：https://www.nowcoder.com/questionTerminal/ceb89f19187b4de3997d9cdef2d551e8?source=relative
来源：牛客网
上图是一个电话的九宫格，如你所见一个数字对应一些字母，因此在国外企业喜欢把电话号码设计成与自己公司名字相对应。例如公司的Help Desk号码是4357，因为4对应H、3对应E、5对应L、7对应P，因此4357就是HELP。同理，TUT - GLOP就代表888 - 4567、310 - GINO代表310 - 4466。
NowCoder刚进入外企，并不习惯这样的命名方式，现在给你一串电话号码列表，请你帮他转换成数字形式的号码，并去除重复的部分。
#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main()
{
	int n;
	map<char, char> mp;
	mp['A'] = '2';
	mp['B'] = '2';
	mp['C'] = '2';

	mp['D'] = '3';
	mp['E'] = '3';
	mp['F'] = '3';

	mp['G'] = '4';
	mp['H'] = '4';
	mp['I'] = '4';

	mp['J'] = '5';
	mp['K'] = '5';
	mp['L'] = '5';

	mp['M'] = '6';
	mp['N'] = '6';
	mp['O'] = '6';

	mp['P'] = '7';
	mp['Q'] = '7';
	mp['R'] = '7';
	mp['S'] = '7';

	mp['T'] = '8';
	mp['U'] = '8';
	mp['V'] = '8';

	mp['W'] = '9';
	mp['X'] = '9';
	mp['Y'] = '9';
	mp['Z'] = '9';

	while (cin >> n){
		string s;
		set<string> ret;
		for (int i = 0; i < n; ++i){
			cin >> s;
			//去除"-"
			string tmp = "";
			for (size_t i = 0; i < s.size(); ++i){
				if (s[i] != '-'){
					tmp += s[i];
				}
			}
			//将字母转换为数字
			for (size_t i = 0; i < tmp.size(); ++i){
				if (tmp[i] >= 'A' && tmp[i] <= 'Z'){
					tmp[i] = mp[tmp[i]];
				}
			}
			//给转换好的字符串转换为正确格式
			tmp.insert(tmp.begin() + 3, '-');
			//插入set中
			ret.insert(tmp);
		}

		for (auto &e : ret){
			cout << e << endl;
		}
		cout << endl;
	}
	return 0;
}