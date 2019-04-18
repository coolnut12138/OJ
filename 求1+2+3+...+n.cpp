//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
class Solution {
public:
	class Sum    //实现一个内部类
	{
	public:		//内部类的构造函数一定设为public，因为class中默认是private的
		Sum()
		{
			sum += i;
			++i;
		}
	};
	int Sum_Solution(int n) {
		sum = 0;
		i = 1;
		Sum arr[n];    //通过调用内部类构造函数
		return sum;
	}
private:
	static int sum;
	static int i;    //使用静态变量可以累加
};

int Solution::sum = 0;
int Solution::i = 1;