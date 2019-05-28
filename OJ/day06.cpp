标题：不要二 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【不要二】二货小易有一个W*H的网格盒子，网格的行编号为0~H - 1，网格的列编号为0~W - 1。每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等
于2。
对于两个格子坐标(x1, y1), (x2, y2)的欧几里得距离为:
((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) 的算术平方根
小易想知道最多可以放多少块蛋糕在网格盒子里。
输入描述：每组数组包含网格长宽W, H，用空格分割.(1 ≤ W、H ≤ 1000)
输出描述:输出一个最多可以放的蛋糕数
	 3 2
	 4

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


【把字符串转换成整数】将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库
函数。 数值为0或者字符串不是一个合法的数值则返回0。
输入描述：输入一个字符串, 包括数字字母符号, 可以为空
输出描述：如果是合法的数值表达则返回该数字，否则返回0
+ 2147483647
1a33

2147483647
0
class Solution {
public:
	int StrToInt(string str) {
		auto sit = str.begin();
		long long num = 0;
		int flag = 1;
		if (*sit == '+'){
			++sit;
		}
		else if (*sit == '-'){
			flag = -1;
			++sit;
		} 
		while(sit != str.end()){
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
};