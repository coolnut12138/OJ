//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
//台阶数  跳法
//  1      1
//  2      2
//  3      3
//  4      5
//  5      8
//典型的斐波那契数列

class Solution {
public:
	int jumpFloor(int number) {
		if (number == 1){
			return 1;
		}
		if (number == 2){
			return 2;
		}

		int step1 = 1;
		int step2 = 2;
		int sum = 0;
		while (number > 2){
			sum = step1 + step2;
			step1 = step2;
			step2 = sum;
			number--;
		}
		return sum;
	}
};