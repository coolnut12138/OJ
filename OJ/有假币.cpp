// write your code here cpp
#include <iostream>
using namespace std;

int main()
{
	int num;    //Ӳ������
	while (cin >> num){
		if (0 == num){
			break;
		}
		int count = 0;
		long long sum = 1;
		//�ҹ��ɣ�3(����3)��֮ǰ��һ��
		//        9(����9)��֮ǰ������
		//        27(����27)��֮ǰ�����Ρ�����������
		while (sum < num){
			sum *= 3;
			++count;
		}
		cout << count << endl;
	}
	return 0;
}