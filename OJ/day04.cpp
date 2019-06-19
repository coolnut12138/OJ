题目：A, B, C三个人是好朋友, 每个人手里都有一些糖果, 我们不知道他们每个人手上具体有多少个糖果, 但是我们知道以下
的信息：A - B, B - C, A + B, B + C.这四个数值.每个字母代表每个人所拥有的糖果数.现在需要通过这四个数值计算出每个
人手里有多少个糖果, 即A, B, C。这里保证最多只有一组整数A, B, C满足所有题设条件。

输入描述：
输入为一行，一共4个整数，分别为A - B，B - C，A + B，B + C，用空格隔开。 范围均在 - 30到30之间(闭区间)。
输出描述：
输出为一行，如果存在满足的整数A，B，C则按顺序输出A，B，C，用空格隔开，行末无空格。 如果不存在这样的整数A，B，C，则输出No
示例1 :
输入：1 - 2 3 4

输出：2 1 3

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int A, B, C;
	vector<int> v;
	int n;
	while (cin >> n)
		v.push_back(n);
	A = (v[0] + v[2]) / 2;
	B = (v[1] + v[3]) / 2;
	C = v[3] - B;
	if ((A - B == v[0]) && (B - C == v[1]) && (A + B == v[2]) && (B + C == v[3])){
		cout << A << " " << B << " " << C << endl;
	}
	else{
		cout << "No" << endl;
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int A = (a + c) / 2;
	int C = (d - b) / 2;
	int B1 = (c - a) / 2;
	int B2 = (b + d) / 2;

	if (B1 != B2){
		cout << "No";
	}
	else {
		cout << A << " " << B1 << " " << C;
	}
	return 0;
}

//输入两个整数M和N，求M的N进制表示方式（M大于0且N大于等于2小于等于16）
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s = "", table = "0123456789ABCDEF";
	int M = 0, N = 0;
	cin >> M >> N;

	if (M == 0)
	{
		s = "0";
	}

	while (M)
	{
		if (M < 0)
		{
			M = -M;
			cout << "-";
		}
		s = table[M % N] + s;
		M /= N;
	}
	cout << s << endl;
	return 0;
}


#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//思路：N进制数，每个进制位的值分别为：X0*N^0 + X1*N^1 + X2*N^2 + ...
//X0、X1、X2就是进制位的值，就是进行取模，余数就是当前低进制的位的值为多少
//然后除掉进制数，进入下一个进制位的计算
int main()
{
	string ret;
	string table = "0123456789ABCDEF";    //进制转换表
	int m, n;
	while (cin >> m >> n){
		bool flag = false;
		//如果是负数，转为整数并标记一下
		if (m < 0){
			m = 0 - m;
			flag = true;
		}
		//按进制换算对应的字符并添加到ret
		while (m){
			ret += table[m%n];
			m /= n;
		}

		if (flag){
			ret += '-';
		}
		reverse(ret.begin(), ret.end());
		cout << ret << endl;
	}
	return 0;
}