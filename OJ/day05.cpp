���ӣ�http://pre.nowcoder.com/questionTerminal/9d1559511b3849deaa71b576fa7009dc?orderByHotValue=0&commentTags=Java
��Դ��ţ����

�����Ĵ�����һ�������ͷ�����һ�����ַ��������硰level�����ߡ�noon���ȵȾ��ǻ��Ĵ��������ǳ�ϲ������ӵ�жԳ����Ļ��Ĵ������յ�ʱ�����õ���������ֱ����ַ���A���ַ���B���������ǳ�������û�а취���ַ���B�����ַ���Aʹ�������ַ�����һ�����Ĵ�������ܻ��������󣬰�����Ѱ���ж����ֲ���취����ʹ�´���һ�����Ĵ�������ַ���B�����λ�ò�ͬ�Ϳ���Ϊ��һ���İ취��
���磺
A = ��aba����B = ��b����������4�ְ�B����A�İ취��
* ��A�ĵ�һ����ĸ֮ǰ: "baba" ���ǻ���
* �ڵ�һ����ĸ��a��֮�� : "abba" �ǻ���
* ����ĸ��b��֮�� : "abba" �ǻ���
* �ڵڶ�����ĸ'a'֮�� "abab" ���ǻ���
�������������Ĵ�Ϊ2

�������� :
ÿ���������ݹ����С�
��һ��Ϊ�ַ���A
�ڶ���Ϊ�ַ���B
�ַ������Ⱦ�С��100��ֻ����Сд��ĸ


������� :
���һ�����֣���ʾ���ַ���B�����ַ���A֮�󹹳�һ�����Ĵ��ķ�����
ʾ��1
����
aba
b
���
2
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


���ӣ�https://www.nowcoder.com/questionTerminal/5a304c109a544aef9b583dce23f5f5db?toCommentId=1474080
��Դ��ţ����

�������� :
����Ϊ���С� ��һ��һ������n(1 <= n <= 100000)����ʾһ����n��Ԫ�� �ڶ���Ϊn��������ÿ��Ԫ��, ÿ����������32λint��Χ�ڡ��Կո�ָ���


������� :
���������������к�����ֵ��
ʾ��1
����
3 - 1 2 1
���
3
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