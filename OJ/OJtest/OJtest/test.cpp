#define _CRT_SECURE_NO_WARNINGS 1
#if 0
//回文串是一个正读反读都一样的字符串，花花喜欢
#include <iostream>
#include <string>
using namespace std;

bool ishuiwen(string& s)
{
	int begin = 0;
	int end = s.size() - 1;
	while (begin < end)    //这里用迭代器不太合适，因为当字符个数为偶数时，begin和end会刚好擦肩而过
	{
		if (s[begin] != s[end]){
			return false;
		}
		++begin;
		--end;
	}
	return true;
}

int main()
{
	string str1;
	string str2;
	string res;
	int count = 0;
	cin >> str1;
	cin >> str2;
	int len = str1.size();
	for (int i = 0; i <= len; i++)    //注意边界条件，最后一个位置也要插入
	{
		res = str1;
		res.insert(i, str2);
		if (ishuiwen(res)){
			count++;
		}
	}
	cout << count << endl;
	return 0;
}
#endif

#if 0
//一个数组有N个元素，求连续子数组的最大和，例如[-1 2 1],结果为3。
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<int> v;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	auto vit = v.begin();
	long long sum = v[0];
	long long max = v[0];
	while (vit != v.end())
	{
		//局部总和 和 全部总和
		//局部总和max：如果加下一个值的和大于前一个值，那么直接更新局部总和的值。
		//全部总和sum：如果局部总和大于全部总和，直接更新全部总和的值为局部总和
		max = (max + *vit) > *vit ? (max + *vit) : *vit;
		sum = max > sum ? max : sum;
		++vit;
	}
	cout << sum << endl;
	system("pause");
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	int n;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	int tmp = v[0] + v[1] - 1;
	int max = v[0] + v[1] - 1;
	for (int i = 1; i < n; i++){
		for (int j = i + 1; j < n; j++){
			tmp = (v[i] + v[j] - abs(i - j)) > tmp ? (v[i] + v[j] - abs(i - j)) : tmp;
			max = tmp > max ? tmp : max;
		}
	}
	cout << max << endl;
	system("pause");
	return 0;
}
#endif


//将字符串转数字，如果遇到不是数字的则直接返回0
#include <iostream>
#include <string>
using namespace std;
int StrToInt(string str) {
	auto sit = str.begin();
	long long num = 0;
	int flag = 1;
	//判断符号
	if (*sit == '+'){
		++sit;
	}
	else if (*sit == '-'){
		flag = -1;
		++sit;
	}
	//逐个转换
	while (sit != str.end()){
		if (*sit >= '0' && *sit <= '9'){
			num = num * 10 + (*sit - '0');
			++sit;
		}
		else{
			num = 0;
			break;
		}
	}
	return num * flag;
}
int main()
{
	string s = "1111";
	cout << StrToInt(s) << endl;
	system("pause");
	return 0;
}


//链接：https://www.nowcoder.com/questionTerminal/1183548cd48446b38da501e58d5944eb
//来源：牛客网
//
//二货小易有一个W*H的网格盒子，网格的行编号为0~H - 1，网格的列编号为0~W - 1。每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。
//对于两个格子坐标(x1, y1), (x2, y2)的欧几里得距离为:
//((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) 的算术平方根
//小易想知道最多可以放多少块蛋糕在网格盒子里。
//
//输入描述 :
//每组数组包含网格长宽W, H，用空格分割.(1 ≤ W、H ≤ 1000)
//
//
//输出描述 :
//	 输出一个最多可以放的蛋糕数
//	 示例1
//	 输入
//	 3 2
//	 输出
//	 4
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int W, H;
	cin >> W >> H;
	int ret = 0;
	if (0 == W % 4 || 0 == H % 4){
		ret = W * H / 2;
	}
	else if (0 == W % 2 && 0 == H % 2){
		ret = W * H / 2 + 2;
	}
	else{
		ret = W * H / 2 + 1;
	}
	cout << ret << endl;
	return 0;
}