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

//�ⷨ�������򣬵���sort��ʱ�临�Ӷ�ΪO(n*logn)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<int> v;
	while (cin >> n){
		v.push_back(n);
	}
	//����
	sort(v.begin(), v.end());
	//���м�������ǳ��ִ�������һ�����
	cout << v[v.size() / 2 - 1] << endl;
	return 0;
}

//�ⷨ�������Ž�
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	int n;
	while (cin >> n){
		v.push_back(n);
	}

	int count = 0;    //���Ԫ�س��ֵĴ���
	int tmp = v[0];    //��¼��ǰԪ��
	//˼·����Ԫ�س���һ�Σ�count����+1�����������Ԫ��count-1��
	//��count��Ϊ0ʱ������tmpΪ��ǰԪ�أ�����count���¼���
	//���������飬���count����Ϊ0����ôtmp���ǳ��ִ�������һ�����
	for (int i = 0; i < v.size(); i++){
		if (v[i] == tmp){
			count++;
		}
		else {
			count--;
		}

		if (count == 0){
			tmp = v[i];
			count++;
		}
	}
	cout << tmp << endl;
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

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str, ret, cur;
	while (getline(cin, str)){    //cin�����ո�ͻ����������ʹ��getline
		for (size_t i = 0; i <= str.size(); ++i){    //Ҫ���������һ��Ԫ�أ������Ų�����©���һ���ַ���
			if (str[i] >= '0' && str[i] <= '9'){
				cur += str[i];
			}
			else {
				//������Ӵ�
				if (ret.size() < cur.size()){
					ret = cur;
				}
				else{
					cur.clear();
				}
			}
		}
		cout << ret << endl;
	}
	return 0;
}
