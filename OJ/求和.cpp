������������ n �� m��������1��2��3.......n ������ȡ������, ʹ��͵��� m, Ҫ���������еĿ�������г���
#include <iostream>
#include <vector>
using namespace std;

void find(vector<int> all, vector<int> tmp, int curPos, int n, int curSum, int m)
{
	if (curPos >= n){
		return;
	}
	curSum += all[curPos];    //����ʱ��
	tmp.push_back(all[curPos]);    //����͵�Ԫ��ѹ������
	if (curSum == m){    //��������е�ֵ����������m������������е�ֵ
		for (size_t i = 0; i < tmp.size() - 1; ++i){
			cout << tmp[i] << " ";
		}
		cout << tmp[tmp.size() - 1] << endl;
	}
	else if (curSum > m){
		return;
	}
	find(all, tmp, curPos + 1, n, curSum, m);    //ѡcurPosλ�õ�ֵ
	tmp.pop_back();
	find(all, tmp, curPos + 1, n, curSum - all[curPos], m);    //��ѡcurPosλ�õ�ֵ
}

int main()
{
	int n, m;
	vector<int> all;    //��� 1~n
	while (cin >> n >> m){
		vector<int> tmp;    //�����͵�Ԫ�ص�ֵ
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