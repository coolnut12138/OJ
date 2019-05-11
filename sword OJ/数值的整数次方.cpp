//数值的整数次方
class Solution {
public:
	double Power(double base, int exponent) {
		long long p = abs((long long)exponent);
		double r = 1.0;
		//快速幂算法，此处先将指数按正数算，如果指数小于0，则取结果的倒数即可。
		while (p){
			if (p & 1){
				r *= base;
			}
			base *= base;
			p >>= 1;
		}
		return exponent < 0 ? 1 / r : r;
	}
};

//快速幂算法  时间复杂度是O(logn)  因为次方是1，2，4，8，16，32，64...
以下以求a的b次方来介绍[1]
把b转换成二进制数。
该二进制数第i位的权为
例如
a^11 = a^(2^0 + 2^1 + 2^3)
11的二进制是1011
11 = 2³×1 + 2²×0 + 2¹×1 + 2º×1
因此，我们将a¹¹转化为算
a^(2^0)+a^(2^1)+a(2^3)

代码如下：
int pow2(int a, int b){
	int ret = 1;
	while (b){
		if (b & 1){
			ret *= a;
		}
		a *= a;
		b >>= 1;
	}
	return ret;
}