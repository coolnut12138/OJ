
//计算数字二进制中最大连续数量的1的个数
#include <iostream>
using namespace std;

int Count(int num)
{
	int count = 0;
	int max = 0;
	while (num){
		//利用与运算判断最后一位是否为1
		if ((num & 1) == 1){
			count++;
		}
		else {
			//如果不是1，则1的连续已经断开，判断个数是否最大
			if (count > max){
				max = count;
			}
			count = 0;
		}
		num >>= 1;
	}
	if (count > max){
		max = count;
	}
	return max;
}

int main()
{
	int num;
	while (cin >> num){
		cout << Count(num) << endl;
	}
	return 0;
}


class LCA {
public:
	int getLCA(int a, int b) {
		// 将两个结点的路径找出来
		vector<int> patha;
		vector<int> pathb;
		patha.push_back(a);
		pathb.push_back(b);
		while (a >= 1){
			patha.push_back(a / 2);
			a /= 2;
		}
		while (b >= 1){
			pathb.push_back(b / 2);
			b /= 2;
		}
		int i = patha.size() - 1;
		int j = pathb.size() - 1;
		//然后进行比较，如果不相等则证明根找到了
		while (i >= 0 && j >= 0){
			if (patha[i] == pathb[j]){
				i--;
				j--;
			}
			else{
				return patha[++i];
			}
		}
		return 1;
	}
};

