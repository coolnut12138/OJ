链接：https://www.nowcoder.com/questionTerminal/286af664b17243deb745f69138f8a800?orderByHotValue=1&page=4&onlyReference=false
来源：牛客网

NowCoder每天要处理许多邮件，但他并不是在收件人列表中，有时候只是被抄送。他认为这些抄送的邮件重要性比自己在收件人列表里的邮件低，因此他要过滤掉这些次要的邮件，优先处理重要的邮件。
现在给你一串抄送列表，请你判断目标用户是否在抄送列表中。

输入描述 :
输入有多组数据，每组数据有两行。

第一行抄送列表，姓名之间用一个逗号隔开。如果姓名中包含空格或逗号，则姓名包含在双引号里。总长度不超过512个字符。

第二行只包含一个姓名，是待查找的用户的名字（姓名要完全匹配）。长度不超过16个字符。
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string name;	//抄送列表
	string name2;	//要匹配的名字
	while (getline(cin, name)){
		int flag = -1;
		getline(cin, name2);
		for (size_t i = 0; i < name.size(); i++){
			string tmp;
			if (name[i] == '"'){	//从第一个双引号开始
				++i;
				while (i < name.size() && name[i] != '"'){	//到最后一个双引号结束
					tmp += name[i];
					++i;
				}
				if (tmp == name2){	//如果tmp等于name2就表示name2在抄送列表中
					flag = 1;
				}
			}
			else if (name[i] != ','){
				while (i < name.size() && name[i] != ','){
					tmp += name[i];
					++i;
				}
				if (tmp == name2){
					flag = 1;
				}
			}
		}
		if (flag == 1){
			cout << "Ignore" << endl;
		}
		else{
			cout << "Important!" << endl;
		}
	}
	return 0;
}