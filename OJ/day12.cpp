//��һ�������Է�Ϊ��������ӣ������������������������ֵ��С����������
#include <iostream>
using namespace std;

bool isPrime(int num)
{
	//�ж��Ƿ�������
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
		sub = litsub = num;		//ע���ʼֵ
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