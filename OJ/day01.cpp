
//���������ַ������ӵ�һ���ַ���ɾ���ڶ����ַ��������е��ַ�����������They are students.��aeiou��ɾ���󣬵�һ���ַ�����ΪThy r stdnts
#include <iostream>
#include <string.h>
using namespace std;

char* deletestr(char* src, const char* const dest)
{
	int destlen = strlen(dest);
	int hashtable[256] = { 0 };
	char *p = src;
	int index = 0;
	for (int i = 0; i < destlen; i++){
		hashtable[(int)dest[i]] = 1;    //�ø��ַ�ת��Ϊascii����λ����1
	}
	while (*p != '\0'){
		if (0 == hashtable[(int)*p]){
			src[index++] = *p;
		}
		++p;
	}
	src[index] = '\0';
	return src;
}

int main()
{
	char src[1024] = { 0 };
	char dest[1024] = { 0 };
	cin.get(src, 1024);    //�㣺�������س�ʱ���������������ո�ͽ���
	cin >> dest;
	char *ret = deletestr(src, dest);
	cout << ret << endl;
	return 0;
}

//c++�ⷨ
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	int hashtable[256] = { 0 };
	//���ַ���2�е�ÿһ���ַ���¼��������
	for (size_t i = 0; i < str2.size(); i++){
		hashtable[str2[i]]++;
	}

	string ret;
	//����ַ���1���ַ�ӳ�䵽hashtable�е�λ��Ϊ0����֤���ַ���2��û������ַ�
	for (size_t i = 0; i < str1.size(); i++){
		if (hashtable[str1[i]] == 0){
			ret += str1[i];
		}
	}
	cout << ret << endl;
	return 0;
}


//ȡ���������ƽ��ֵ�ĺ�
��������������ĵ�һ��Ϊһ��������n(1 <= n <= 10^5)
		 ����ĵڶ��а���3*n������a_i(1 <= a_i <= 10^9),��ʾÿ������ѡ�ֵ�ˮƽֵ
������������һ��������ʾ���ж����ˮƽֵ�ܺ����ֵ
���磺���� ��
	2
	5 2 8 5 1 5
	�����
	10
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int que_num = 0;
	while (cin >> que_num){
		vector<int> v;
		int peo_ave = 0;

		while (cin >> peo_ave)
		{
			v.push_back(peo_ave);
		}

		sort(v.begin(), v.end());
		auto it = v.end() - 1;
		long long sum = 0;	//�㣺��Ϊ��ֵ���ܹ�����int�Ͳ����ţ�������long long��
		for (int i = 0; i < que_num; i++){
			--it;
			sum += *it;
			--it;
		}
		v.clear();
		cout << sum << endl;
	}
	return 0;
}

//�ⷨ��
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;    //�������
	while (cin >> n){
		long long sum = 0;
		vector<int> v;
		v.resize(n * 3);
		for (int i = 0; i < n * 3; ++i){
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		for (int i = n; i <= 3 * n - 2; i += 2){
			sum += v[i];
		}
		cout << sum << endl;
	}
	return 0;
}