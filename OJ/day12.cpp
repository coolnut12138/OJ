//将一个数可以分为两个数相加，若两个数都是素数，求相差值最小的两个素数
#include <iostream>
using namespace std;

bool isPrime(int num)
{
	//判断是否是素数
	for (int i = 2; i < num; i++){
		if (0 == num % i){
			return false;
		}
	}
	return true;
}

int main()
{
	int num, i, j, res1, res2;
	int sub, litsub;
	while (cin >> num){
		sub = litsub = num;		//注意初始值
		for (i = 2; i < num - 2; i++){
			j = num - i;
			if (isPrime(i) && isPrime(j)){
				sub = abs(i - j);
			}
			if (sub < litsub){
				litsub = sub;
				res1 = i;
				res2 = j;
			}
		}
		cout << res1 << endl;
		cout << res2 << endl;
	}
	system("pause");
	return 0;
}