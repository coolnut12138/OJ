���ӣ�https://www.nowcoder.com/questionTerminal/5973a31d58234b068fa1fe34f7290855?pos=104&orderByHotValue=1
��Դ��ţ����

NowCoderÿ��Ҫ�����ͻ�д�����ʼ�����������֪�����һ���ʼ��а�������ռ��ˣ��ռ�������֮�����һ�����źͿո����������ռ�������Ҳ�����ո�򶺺ţ���������Ҫ��˫���Ű�����
���ڸ���һ���ռ����������������������Ӧ���ռ����б�

�������� :
��������������ݡ�

ÿ�����ݵĵ�һ����һ������n(1��n��128)����ʾ������n��������

������n�У�ÿһ�а���һ���ռ��˵��������������Ȳ�����16���ַ���
// write your code here cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n;    //n������
	string name;
	while (cin >> n){
		cin.get();    //���ն���Ŀո�س�
		for (int i = 0; i < n - 1; ++i){
			getline(cin, name);
			if (name.find(",") == string::npos && name.find(" ") == string::npos){
				cout << name << ", ";
			}
			else{
				cout << "\"" << name << "\"" << ", ";
			}
		}
		getline(cin, name);
		if (name.find(",") == string::npos && name.find(" ") == string::npos){
			cout << name << endl;
		}
		else{
			cout << "\"" << name << "\"" << endl;
		}
	}
	return 0;
}