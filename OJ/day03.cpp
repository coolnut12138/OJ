链接：https://www.nowcoder.com/questionTerminal/eac8c671a0c345b38aa0c07aba40097b?orderByHotValue=0&page=1&onlyReference=false
来源：牛客网

输入描述 :
每个测试输入包含 n个空格分割的n个整数，n不超过100，其中有一个整数出现次数大于等于n / 2。


输出描述 :
输出出现次数大于等于n / 2的数。
示例1
输入
3 9 3 2 5 6 7 3 2 3 3 3
输出
3
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	int n;
	int arr[10240] = { 0 };
	int len = 0;
	while (cin >> n){
		v.push_back(n);
		/*if (cin.get() == '\n'){
		break;
		}*/
	}
	len = v.size() / 2;
	auto begin = v.begin();
	while (begin != v.end()){
		arr[*begin]++;
		begin++;
	}
	for (int i = 0; i < 10240; i++){
		if (arr[i] >= len){
			cout << i << endl;
		}
	}
	system("pause");
	return 0;
}

题目描述
读入一个字符串str，输出字符串str中的连续最长的数字串
输入描述 :
个测试输入包含1个测试用例，一个字符串str，长度不超过255。
输出描述 :
在一行内输出str中里连续最长的数字串。
示例1
输入
abcd12345ed125ss123456789
输出
123456789
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str, res, cur;
	getline(cin, str);
	for (size_t i = 0; i <= str.size(); i++){
		if (str[i] >= '0' && str[i] <= '9'){
			cur += str[i];
		}
		else{
			if (res.size() < cur.size()){
				res = cur;
			}
			else{
				cur.clear();
			}
		}
	}
	cout << res << endl;
	system("pause");
	return 0;
}