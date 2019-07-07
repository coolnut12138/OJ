nowcoder生活在充满危险和阴谋的年代，密码加密是将大写字母修改为该字母的第五个，现在给密码，让解码
// write your code here cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string code;    //密文
	while (getline(cin, code)){
		string text = "";    //明文
		for (size_t i = 0; i < code.size(); i++){
			if (code[i] >= 'A' && code[i] <= 'Z'){
				code[i] -= 5;
				if (code[i] < 65){    //如果越界就从后面开始减
					code[i] = 'Z' - ('A' - code[i]) + 1;
				}
				text += code[i];
			}
			else{
				text += code[i];
			}
		}
		cout << text << endl;
	}
	return 0;
}



//因子个数，因式分解
链接：https://www.nowcoder.com/questionTerminal/e8fb8f89f5d147ec92fd8ecfefe89b0d
来源：牛客网
一个正整数可以分解成一个或多个数组的积。例如36 = 2 * 2 * 3 * 3，即包含2和3两个因子。NowCoder最近在研究因子个数的分布规律，现在给出一系列正整数，他希望你开发一个程序输出每个正整数的因子个数。

输入描述 :
输入包括多组数据。
每组数据仅有一个整数n(2≤n≤100000)。
// write your code here cpp
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, count;
	while (cin >> n){
		count = 0;
		for (int i = 2; i < sqrt(n); i++){
			if (n % i == 0){
				while (n % i == 0){
					n /= i;
				}
				count++;
			}
		}
		if (n != 1){
			count++;
		}
		cout << count << endl;
	}
	return 0;
}