���ӣ�https://www.nowcoder.com/questionTerminal/eac8c671a0c345b38aa0c07aba40097b?orderByHotValue=0&page=1&onlyReference=false
��Դ��ţ����

�������� :
ÿ������������� n���ո�ָ��n��������n������100��������һ���������ִ������ڵ���n / 2��


������� :
������ִ������ڵ���n / 2������
ʾ��1
����
3 9 3 2 5 6 7 3 2 3 3 3
���
3
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	int n;
	int arr[10240] = { 0 };
	int len = 0;
	while (cin >> n){
		v.push_back(n);
		/*if (cin.get() == '\n'){
		break;
		}*/
	}
	len = v.size() / 2;
	auto begin = v.begin();
	while (begin != v.end()){
		arr[*begin]++;
		begin++;
	}
	for (int i = 0; i < 10240; i++){
		if (arr[i] >= len){
			cout << i << endl;
		}
	}
	system("pause");
	return 0;
}

��Ŀ����
����һ���ַ���str������ַ���str�е�����������ִ�
�������� :
�������������1������������һ���ַ���str�����Ȳ�����255��
������� :
��һ�������str��������������ִ���
ʾ��1
����
abcd12345ed125ss123456789
���
123456789
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str, res, cur;
	getline(cin, str);
	for (size_t i = 0; i <= str.size(); i++){
		if (str[i] >= '0' && str[i] <= '9'){
			cur += str[i];
		}
		else{
			if (res.size() < cur.size()){
				res = cur;
			}
			else{
				cur.clear();
			}
		}
	}
	cout << res << endl;
	system("pause");
	return 0;
}