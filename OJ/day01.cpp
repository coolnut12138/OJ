
//输入两个字符串，从第一个字符中删除第二个字符串中所有的字符，例如输入They are students.和aeiou，删除后，第一个字符串变为Thy r stdnts
#include <iostream>
#include <string.h>
using namespace std;

char* deletestr(char* src, const char* const dest)
{
	int destlen = strlen(dest);
	int hashtable[256] = { 0 };
	char *p = src;
	int index = 0;
	for (int i = 0; i < destlen; i++){
		hashtable[(int)dest[i]] = 1;    //让该字符转换为ascii所在位置置1
	}
	while (*p != '\0'){
		if (0 == hashtable[(int)*p]){
			src[index++] = *p;
		}
		++p;
	}
	src[index] = '\0';
	return src;
}

int main()
{
	char src[1024] = { 0 };
	char dest[1024] = { 0 };
	cin.get(src, 1024);    //点：当遇到回车时结束而不是遇到空格就结束
	cin >> dest;
	char *ret = deletestr(src, dest);
	cout << ret << endl;
	return 0;
}

//c++解法
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	int hashtable[256] = { 0 };
	//将字符串2中的每一个字符记录在数组中
	for (size_t i = 0; i < str2.size(); i++){
		hashtable[str2[i]]++;
	}

	string ret;
	//如果字符串1的字符映射到hashtable中的位置为0，则证明字符串2中没有这个字符
	for (size_t i = 0; i < str1.size(); i++){
		if (hashtable[str1[i]] == 0){
			ret += str1[i];
		}
	}
	cout << ret << endl;
	return 0;
}


//取队伍中最大平均值的和
输入描述：输入的第一行为一个正整数n(1 <= n <= 10^5)
		 输入的第二行包括3*n个整数a_i(1 <= a_i <= 10^9),表示每个参赛选手的水平值
输出描述：输出一个整数表示所有队伍的水平值总和最大值
例如：输入 ：
	2
	5 2 8 5 1 5
	输出：
	10
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int que_num = 0;
	while (cin >> que_num){
		vector<int> v;
		int peo_ave = 0;

		while (cin >> peo_ave)
		{
			v.push_back(peo_ave);
		}

		sort(v.begin(), v.end());
		auto it = v.end() - 1;
		long long sum = 0;	//点：因为数值可能过大导致int型不够放，所以用long long型
		for (int i = 0; i < que_num; i++){
			--it;
			sum += *it;
			--it;
		}
		v.clear();
		cout << sum << endl;
	}
	return 0;
}

//解法二
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;    //组的数量
	while (cin >> n){
		long long sum = 0;
		vector<int> v;
		v.resize(n * 3);
		for (int i = 0; i < n * 3; ++i){
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		for (int i = n; i <= 3 * n - 2; i += 2){
			sum += v[i];
		}
		cout << sum << endl;
	}
	return 0;
}