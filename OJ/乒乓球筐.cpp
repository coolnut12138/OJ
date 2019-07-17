链接：https://www.nowcoder.com/questionTerminal/bb4f1a23dbb84fd7b77be1fbe9eaaf32?toCommentId=57018
来源：牛客网

nowcoder有两盒（A、B）乒乓球，有红双喜的、有亚力亚的……现在他需要判别A盒是否包含了B盒中所有的种类，并且每种球的数量不少于B盒中的数量，该怎么办呢？
// write your code here cpp
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	string A;
	string B;
	while (cin >> A >> B){
		bool status = true;
		map<char, int> Amp, Bmp;
		//使用map的特性
		for (auto e : A){
			Amp[e]++;
		}
		for (auto e : B){
			Bmp[e]++;
		}
		for (auto e : Bmp){
			if (Amp[e.first] < e.second){
				status = false;
				break;
			}
		}
		switch (status){
		case true:
			cout << "Yes" << endl;
			break;
		case false:
			cout << "No" << endl;
			break;
		}
	}
	return 0;
}