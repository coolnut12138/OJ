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

//no.2
思路：((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) == 4看起来是一个无解的表达式。
但是可以进行加法表达式分解：
1 + 3 = 4
3 + 1 = 4
2 + 2 = 4
0 + 4 = 4
4 + 0 = 4
仔细分析前三个表达式是不可能的，因为(x1 - x2) * (x1 - x2)表达式结果不能等于2或3。
也就是说((x1 - x2) * (x1 - x2) 和(y1 - y2) * (y1 - y2))两个表达式一个等于0，一个等于4.
可以看出：假设放蛋糕的位置是(x1, y1)，则不能放蛋糕的位置(x2, y2)，满足x1 == x2, y1 - y2 == 2或者x1 - x2 == 2, y1 == y2.
【解题思路】：
仔细读理解了上面的题目解读，本题就非常简单了，使用vector<vector<int>>定义一个二维数组，resize开
空间并初始化，每个位置初始化为1，表示当蛋糕，a[i][j]位置放蛋糕，则可以标记处a[i][j + 2]和a[i + 2][j]位置
不能放蛋糕，遍历一遍二维数组，标记处不能放蛋糕的位置，统计也就统计出了当蛋糕的位置数。
#include <iostream>
#include <vector>
int main()
{
	using namespace std;
	int m, n;
	int res = 0;
	vector<vector<int>> v;
	cin >> m >> n;
	//将一个二维数组全部初始化为1
	v.resize(m);
	for (auto& e : v){
		e.resize(n, 1);
	}

	//遍历二维数组，如果有不能放蛋糕的位置，将其置为0，并且顺便计算出了蛋糕的个数
	for (size_t i = 0; i < v.size(); i++){
		for (size_t j = 0; j < v[0].size(); j++){
			if (v[i][j] == 1){
				res++;    //蛋糕数量
				if (i + 2 < m){
					v[i + 2][j] = 0;
				}
				if (j + 2 < n){
					v[i][j + 2] = 0;
				}
			}
		}
	}
	cout << res << endl;
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