���ӣ�https://www.nowcoder.com/questionTerminal/bb4f1a23dbb84fd7b77be1fbe9eaaf32?toCommentId=57018
��Դ��ţ����

nowcoder�����У�A��B��ƹ�����к�˫ϲ�ġ��������ǵġ�����������Ҫ�б�A���Ƿ������B�������е����࣬����ÿ���������������B���е�����������ô���أ�
// write your code here cpp
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	string A;
	string B;
	while (cin >> A >> B){
		bool status = true;
		map<char, int> Amp, Bmp;
		//ʹ��map������
		for (auto e : A){
			Amp[e]++;
		}
		for (auto e : B){
			Bmp[e]++;
		}
		for (auto e : Bmp){
			if (Amp[e.first] < e.second){
				status = false;
				break;
			}
		}
		switch (status){
		case true:
			cout << "Yes" << endl;
			break;
		case false:
			cout << "No" << endl;
			break;
		}
	}
	return 0;
}