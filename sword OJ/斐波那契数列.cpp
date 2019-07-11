//斐波那契数列
class Solution {
public:
	int Fibonacci(int n) {
		/*递归
		if(n == 0){
		return 0;
		}

		if(n >= 1 && n <= 2){
		return 1;
		}
		else{
		return Fibonacci(n - 1) + Fibonacci(n - 2);
		}*/
		//非递归=-----动态规划
		class Solution {
		public:
			int climbStairs(int n) {
				if (n < 1){
					return 0;
				}
				if (n == 1){
					return 1;
				}
				if (n == 2){
					return 2;
				}
				//申请一个数组将数字存储下来，但是这样的空间复杂度变为了O(n)
				int *record = new int[n + 1];
				record[0] = 1;
				record[1] = 1;
				for (int i = 2; i <= n; i++){
					record[i] = record[i - 1] + record[i - 2];
				}
				return record[n];
				delete[] record;

			}
		};

		//第三种方法：动态规划。不用创建数组，因为求第 n 项只需要第 n - 1 项 和 第 n - 2 项即可
		if (n == 0){
			return 0;
		}
		int a = 1;
		int b = 1;
		int ret = 1;
		for (int i = 0; i <= n - 2; i++){
			ret = a + b;
			a = b;
			b = ret;
		}
		return ret;
	}
};