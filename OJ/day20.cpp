将字符串逆转
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string str;
	while (cin >> str){
		reverse(str.begin(), str.end());
		cout << str << endl;
	}
	system("pause");
	return 0;
}

//求两个字符串的最大公共子串的长度
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a, b;
	int max = 0;
	while (cin >> a >> b){
		int len = a.size();
		for (int i = len; i > 1; i--){
			for (int j = 0; j < len; j++){
				if (i + j <= len){
					string tmp = a.substr(j, i);
					size_t t = b.find(tmp);
					if (t != string::npos && tmp.size() > max){
						max = tmp.size();
					}
				}
			}
		}
		cout << max << endl;
	}
	return 0;
}