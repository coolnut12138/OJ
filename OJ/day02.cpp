链接：https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471?orderByHotValue=1&page=1&onlyReference=false
来源：牛客网

牛牛定义排序子序列为一个数组中一段连续的子序列, 并且这段子序列是非递增或者非递减排序的。牛牛有一个长度为n的整数数组A, 他现在有一个任务是把数组A分为若干段排序子序列, 牛牛想知道他最少可以把这个数组分为几段排序子序列.
如样例所示, 牛牛可以把数组A划分为[1, 2, 3]和[2, 2, 1]两个排序子序列, 至少需要划分为2个排序子序列, 所以输出2

输入描述 :
输入的第一行为一个正整数n(1 ≤ n ≤ 10 ^ 5)

第二行包括n个整数A_i(1 ≤ A_i ≤ 10 ^ 9), 表示数组A的每个数字。

输出描述 :
输出一个整数表示牛牛可以将A最少划分为多少段排序子序列
示例1
输入
6
1 2 3 2 2 1
输出
2
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	v.resize(n);
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	int ret = 1;
	for (int i = 1; i < n - 1; i++)
	{
		if ((v[i - 1] < v[i] && v[i] > v[i + 1])
			|| (v[i - 1] > v[i] && v[i] < v[i + 1])){
			ret++;
			if (i != n - 3){
				i++;
			}
		}
	}
	cout << ret << endl;
	return 0;
}

题目描述
将一句话的单词进行倒置，标点不倒置。比如 I like beijing.经过函数后变为：beijing.like I
输入描述 :
每个测试输入包含1个测试用例： I like beijing.输入用例长度不超过100
输出描述 :
依次输出倒置之后的字符串, 以空格分割
示例1
输入
I like beijing.
输出
beijing.like I
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	getline(cin, s);

	reverse(s.begin(), s.end());
	auto sit1 = s.begin();
	while (sit1 != s.end()){
		auto sit2 = sit1;
		while (sit2 != s.end() && *sit2 != ' '){
			++sit2;
		}
		reverse(sit1, sit2);

		if (sit2 != s.end()){
			//指向空格的下一个位置
			sit1 = sit2 + 1;
		}
		else{
			sit1 = sit2;
		}
	}
	cout << s << endl;
	return 0;
}


/*#include <iostream>
#include <string>
using namespace std;

int main()
{
string s1, s2;
cin >> s2;
while(cin >> s1){
s2 = s1 + " " + s2;
}
cout << s2 << endl;
}*/