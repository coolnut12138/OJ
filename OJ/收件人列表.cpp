链接：https://www.nowcoder.com/questionTerminal/5973a31d58234b068fa1fe34f7290855?pos=104&orderByHotValue=1
来源：牛客网

NowCoder每天要给许多客户写电子邮件。正如你所知，如果一封邮件中包含多个收件人，收件人姓名之间会用一个逗号和空格隔开；如果收件人姓名也包含空格或逗号，则姓名需要用双引号包含。
现在给你一组收件人姓名，请你帮他生成相应的收件人列表。

输入描述 :
输入包含多组数据。

每组数据的第一行是一个整数n(1≤n≤128)，表示后面有n个姓名。

紧接着n行，每一行包含一个收件人的姓名。姓名长度不超过16个字符。
// write your code here cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n;    //n个姓名
	string name;
	while (cin >> n){
		cin.get();    //吸收多余的空格回车
		for (int i = 0; i < n - 1; ++i){
			getline(cin, name);
			if (name.find(",") == string::npos && name.find(" ") == string::npos){
				cout << name << ", ";
			}
			else{
				cout << "\"" << name << "\"" << ", ";
			}
		}
		getline(cin, name);
		if (name.find(",") == string::npos && name.find(" ") == string::npos){
			cout << name << endl;
		}
		else{
			cout << "\"" << name << "\"" << endl;
		}
	}
	return 0;
}