���ӣ�https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471?orderByHotValue=1&page=1&onlyReference=false
��Դ��ţ����

ţţ��������������Ϊһ��������һ��������������, ��������������Ƿǵ������߷ǵݼ�����ġ�ţţ��һ������Ϊn����������A, ��������һ�������ǰ�����A��Ϊ���ɶ�����������, ţţ��֪�������ٿ��԰���������Ϊ��������������.
��������ʾ, ţţ���԰�����A����Ϊ[1, 2, 3]��[2, 2, 1]��������������, ������Ҫ����Ϊ2������������, �������2

�������� :
����ĵ�һ��Ϊһ��������n(1 �� n �� 10 ^ 5)

�ڶ��а���n������A_i(1 �� A_i �� 10 ^ 9), ��ʾ����A��ÿ�����֡�

������� :
���һ��������ʾţţ���Խ�A���ٻ���Ϊ���ٶ�����������
ʾ��1
����
6
1 2 3 2 2 1
���
2
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	v.resize(n);
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	int ret = 1;
	for (int i = 1; i < n - 1; i++)
	{
		if ((v[i - 1] < v[i] && v[i] > v[i + 1])
			|| (v[i - 1] > v[i] && v[i] < v[i + 1])){
			ret++;
			if (i != n - 3){
				i++;
			}
		}
	}
	cout << ret << endl;
	return 0;
}

��Ŀ����
��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing.�����������Ϊ��beijing.like I
�������� :
ÿ�������������1������������ I like beijing.�����������Ȳ�����100
������� :
�����������֮����ַ���, �Կո�ָ�
ʾ��1
����
I like beijing.
���
beijing.like I
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	getline(cin, s);

	reverse(s.begin(), s.end());
	auto sit1 = s.begin();
	while (sit1 != s.end()){
		auto sit2 = sit1;
		while (sit2 != s.end() && *sit2 != ' '){
			++sit2;
		}
		reverse(sit1, sit2);

		if (sit2 != s.end()){
			//ָ��ո����һ��λ��
			sit1 = sit2 + 1;
		}
		else{
			sit1 = sit2;
		}
	}
	cout << s << endl;
	return 0;
}


/*#include <iostream>
#include <string>
using namespace std;

int main()
{
string s1, s2;
cin >> s2;
while(cin >> s1){
s2 = s1 + " " + s2;
}
cout << s2 << endl;
}*/