//喝汽水
#include <iostream>
#include <vector>
using namespace std;

int drinkCount(int n)
{
	int empty = 0, count = 0;
	while (n > 1){
		//记录喝一次的后的空瓶子数
		empty = n / 3 + n % 3;
		//记录本次能喝几瓶
		count += n / 3;
		//让n更新为当前的空瓶数
		n = empty;
		if (n == 2){
			count++;
			break;
		}
	}
	return count;
}

int main()
{
	vector<int> v;
	int n;
	while (cin >> n){
		v.push_back(n);
	}
	for (size_t i = 0; i < v.size(); i++){
		if (v[i] != 0){
			cout << drinkCount(v[i]) << endl;
		}
	}
	return 0;
}

链接：https://www.nowcoder.com/questionTerminal/181a1a71c7574266ad07f9739f791506

查找两个字符串a, b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。

输入描述 :
输入两个字符串

输出描述 :
返回重复出现的字符
示例1
输入
abcdefghijklmnop
abcsafjklmnopqrstuvw
输出
jklmnop

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a, b;
	while (cin >> a >> b){
		if (a.size() > b.size()){
			swap(a, b);
		}
		string maxlen;
		for (size_t i = 0; i < a.size(); i++){
			for (size_t j = i; j < a.size(); j++){
				string temp = a.substr(i, j - i + 1);
				//string::find 没找到返回npos
				if (int(b.find(temp) == string::npos)){
					continue;
				}
				else if (maxlen.size() < temp.size()){
					maxlen = temp;
				}
			}
		}
		cout << maxlen << endl;
	}
	return 0;
}
