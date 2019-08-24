//算法描述:
//牛家村的货币是一种很神奇的连续货币.
//他们货币的最大面额是n, 并且一共有面额为1, 面额为2, ..., 面额为n, n种面额的货币.
//牛牛每次购买商品都会带上所有面额的货币, 支付时会选择给出数量最小的方案.
//现在告诉你牛牛将要购买的商品的价格, 你能算出牛牛支付的硬币数量吗 ?
//第一行两个整数n, m.表示货币的最大面额和商品的价格.
//
//输出描述 :
//	一个整数表示牛牛支付的硬币数量.
//	输入6 7
//	输出 2
//	输入 4 10
//	输出3
//
//算法思路 : 
//这是一道典型的贪心算法题解.因为要选择给出数量最小的方案, 所以每次应该选择最大的硬币.直到最大面额再加1时会超过价格时, 再选取小一点的硬币面额进行添加, 直到与价格一样.
//举例 :
//6 7, 先计算出7中可以用多少个面额为6的硬币, A = 7 / 6 = 1, 再用7 - 1 * 6 = 1; 再只需一个面额为1的硬币就满足要求.
//4 10, 先计算出10中可以用多少个面额为4的硬币, A = 10 / 4 = 2, 再计算出剩余10 - 4 * 2 = 2, 只需一个面额为2的硬币就满足要求.
#include <iostream>
using namespace std;
int main()
{
	int n, m;	//n为最大面额，m为商品价格
	while (cin >> n >> m) {
		int count = 0;
		while (m) {
			if (m >= n) {
				//商品价格大于最大面额
				int tmpCount = m / n;
				count += tmpCount;
				m = m - n * tmpCount;
			}
			else {
				n = m;
			}
		}
		cout << count << endl;
	}
	return 0;
}