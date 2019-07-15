输入两个整数 n 和 m，从数列1，2，3.......n 中随意取几个数, 使其和等于 m, 要求将其中所有的可能组合列出来
#include <iostream>
#include <vector>
using namespace std;

void find(vector<int> all, vector<int> tmp, int curPos, int n, int curSum, int m)
{
	if (curPos >= n){
		return;
	}
	curSum += all[curPos];    //求临时和
	tmp.push_back(all[curPos]);    //将求和的元素压入数组
	if (curSum == m){    //如果数组中的值加起来等于m，则输出数组中的值
		for (size_t i = 0; i < tmp.size() - 1; ++i){
			cout << tmp[i] << " ";
		}
		cout << tmp[tmp.size() - 1] << endl;
	}
	else if (curSum > m){
		return;
	}
	find(all, tmp, curPos + 1, n, curSum, m);    //选curPos位置的值
	tmp.pop_back();
	find(all, tmp, curPos + 1, n, curSum - all[curPos], m);    //不选curPos位置的值
}

int main()
{
	int n, m;
	vector<int> all;    //存放 1~n
	while (cin >> n >> m){
		vector<int> tmp;    //存放求和的元素的值
		int curSum = 0;
		for (size_t i = 0; i < n; ++i){
			all.push_back(i + 1);
		}
		if (n > m){
			n = m;
		}
		find(all, tmp, 0, n, curSum, m);
	}
	return 0;
}