������n���ַ����ַ��������������ַ������ȶ��ǲ�ͬ�ġ��������ѧϰ���������ַ��������򷽷��� 
1.�����ַ������ֵ����������磺
"car" < "carriage" < "cats" < "doggies < "koala"
2.�����ַ����ĳ����������磺
"car" < "cats" < "koala" < "doggies" < "carriage"
������֪���Լ�����Щ�ַ�������˳���Ƿ��������������򷽷�������Ҫæ�ų���Ҷ��������Ҫ������æ��֤��

�������� :
�����һ��Ϊ�ַ�������n(n �� 100)
��������n��, ÿ��һ���ַ���, �ַ������Ⱦ�С��100������Сд��ĸ���
������� :
�����Щ�ַ����Ǹ����ֵ������ж����Ǹ��ݳ����������"lexicographically",

������ݳ������ж������ֵ����������"lengths",

������ַ�ʽ���������"both"���������"none"
ʾ��1

����
3
a
aa
bbb
���
both
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isDir(vector<string>& v)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i] > v[i + 1]){
			return false;
		}
	}
	return true;
}

bool isLen(vector<string>& v)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i].size() > v[i + 1].size())
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	vector<string> v;
	v.resize(n);

	for (int i = 0; i < n; i++){
		cin >> v[i];
	}

	if (isDir(v) && !isLen(v)){
		cout << "lexicographically" << endl;
	}
	if (!isDir(v) && isLen(v)){
		cout << "lengths" << endl;
	}
	if (isDir(v) && isLen(v)){
		cout << "both" << endl;
	}
	if (!isDir(v) && !isLen(v)){
		cout << "none" << endl;
	}
	return 0;
}

//����С������
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	while (a%b){
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return b;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << (a*b / gcd(a, b)) << endl;
	return 0;
}