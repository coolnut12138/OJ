#define _CRT_SECURE_NO_WARNINGS 1
#if 0
//���Ĵ���һ������������һ�����ַ���������ϲ��
#include <iostream>
#include <string>
using namespace std;

bool ishuiwen(string& s)
{
	int begin = 0;
	int end = s.size() - 1;
	while (begin < end)    //�����õ�������̫���ʣ���Ϊ���ַ�����Ϊż��ʱ��begin��end��պò������
	{
		if (s[begin] != s[end]){
			return false;
		}
		++begin;
		--end;
	}
	return true;
}

int main()
{
	string str1;
	string str2;
	string res;
	int count = 0;
	cin >> str1;
	cin >> str2;
	int len = str1.size();
	for (int i = 0; i <= len; i++)    //ע��߽����������һ��λ��ҲҪ����
	{
		res = str1;
		res.insert(i, str2);
		if (ishuiwen(res)){
			count++;
		}
	}
	cout << count << endl;
	return 0;
}
#endif

#if 0
//һ��������N��Ԫ�أ�����������������ͣ�����[-1 2 1],���Ϊ3��
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<int> v;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	auto vit = v.begin();
	long long sum = v[0];
	long long max = v[0];
	while (vit != v.end())
	{
		//�ֲ��ܺ� �� ȫ���ܺ�
		//�ֲ��ܺ�max���������һ��ֵ�ĺʹ���ǰһ��ֵ����ôֱ�Ӹ��¾ֲ��ܺ͵�ֵ��
		//ȫ���ܺ�sum������ֲ��ܺʹ���ȫ���ܺͣ�ֱ�Ӹ���ȫ���ܺ͵�ֵΪ�ֲ��ܺ�
		max = (max + *vit) > *vit ? (max + *vit) : *vit;
		sum = max > sum ? max : sum;
		++vit;
	}
	cout << sum << endl;
	system("pause");
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	int n;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	int tmp = v[0] + v[1] - 1;
	int max = v[0] + v[1] - 1;
	for (int i = 1; i < n; i++){
		for (int j = i + 1; j < n; j++){
			tmp = (v[i] + v[j] - abs(i - j)) > tmp ? (v[i] + v[j] - abs(i - j)) : tmp;
			max = tmp > max ? tmp : max;
		}
	}
	cout << max << endl;
	system("pause");
	return 0;
}
#endif


//���ַ���ת���֣���������������ֵ���ֱ�ӷ���0
#include <iostream>
#include <string>
using namespace std;
int StrToInt(string str) {
	auto sit = str.begin();
	long long num = 0;
	int flag = 1;
	//�жϷ���
	if (*sit == '+'){
		++sit;
	}
	else if (*sit == '-'){
		flag = -1;
		++sit;
	}
	//���ת��
	while (sit != str.end()){
		if (*sit >= '0' && *sit <= '9'){
			num = num * 10 + (*sit - '0');
			++sit;
		}
		else{
			num = 0;
			break;
		}
	}
	return num * flag;
}
int main()
{
	string s = "1111";
	cout << StrToInt(s) << endl;
	system("pause");
	return 0;
}


//���ӣ�https://www.nowcoder.com/questionTerminal/1183548cd48446b38da501e58d5944eb
//��Դ��ţ����
//
//����С����һ��W*H��������ӣ�������б��Ϊ0~H - 1��������б��Ϊ0~W - 1��ÿ������������Է�һ�鵰�⣬�������鵰���ŷ����þ��벻�ܵ���2��
//����������������(x1, y1), (x2, y2)��ŷ����þ���Ϊ:
//((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) ������ƽ����
//С����֪�������ԷŶ��ٿ鵰������������
//
//�������� :
//ÿ������������񳤿�W, H���ÿո�ָ�.(1 �� W��H �� 1000)
//
//
//������� :
//	 ���һ�������Էŵĵ�����
//	 ʾ��1
//	 ����
//	 3 2
//	 ���
//	 4
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int W, H;
	cin >> W >> H;
	int ret = 0;
	if (0 == W % 4 || 0 == H % 4){
		ret = W * H / 2;
	}
	else if (0 == W % 2 && 0 == H % 2){
		ret = W * H / 2 + 2;
	}
	else{
		ret = W * H / 2 + 1;
	}
	cout << ret << endl;
	return 0;
}