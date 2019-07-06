// write your code here cpp
#include <iostream>
using namespace std;

int main()
{
	int num;    //硬币数量
	while (cin >> num){
		if (0 == num){
			break;
		}
		int count = 0;
		long long sum = 1;
		//找规律：3(包括3)个之前是一次
		//        9(包括9)个之前是两次
		//        27(包括27)个之前是三次。。。。。。
		while (sum < num){
			sum *= 3;
			++count;
		}
		cout << count << endl;
	}
	return 0;
}