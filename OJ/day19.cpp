//����ˮ
#include <iostream>
#include <vector>
using namespace std;

int drinkCount(int n)
{
	int empty = 0, count = 0;
	while (n > 1){
		//��¼��һ�εĺ�Ŀ�ƿ����
		empty = n / 3 + n % 3;
		//��¼�����ܺȼ�ƿ
		count += n / 3;
		//��n����Ϊ��ǰ�Ŀ�ƿ��
		n = empty;
		if (n == 2){
			count++;
			break;
		}
	}
	return count;
}

int main()
{
	vector<int> v;
	int n;
	while (cin >> n){
		v.push_back(n);
	}
	for (size_t i = 0; i < v.size(); i++){
		if (v[i] != 0){
			cout << drinkCount(v[i]) << endl;
		}
	}
	return 0;
}

���ӣ�https://www.nowcoder.com/questionTerminal/181a1a71c7574266ad07f9739f791506

���������ַ���a, b�е�������Ӵ������ж��������ڽ϶̴������ȳ��ֵ��Ǹ���

�������� :
���������ַ���

������� :
�����ظ����ֵ��ַ�
ʾ��1
����
abcdefghijklmnop
abcsafjklmnopqrstuvw
���
jklmnop
�ⷨһ��
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a, b;
	while (cin >> a >> b){
		if (a.size() > b.size()){
			swap(a, b);
		}
		string maxlen;
		for (size_t i = 0; i < a.size(); i++){
			for (size_t j = i; j < a.size(); j++){
				string temp = a.substr(i, j - i + 1);
				//string::find û�ҵ�����npos
				if (int(b.find(temp) == string::npos)){
					continue;
				}
				else if (maxlen.size() < temp.size()){
					maxlen = temp;
				}
			}
		}
		cout << maxlen << endl;
	}
	return 0;
}

//��̬�滮����
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2){
		if (s1.size() > s2.size()){
			swap(s1, s2);
		}

		int len1 = s1.size();
		int len2 = s2.size();
		int i, j, start = 0, max = 0;
		vector<vector<int>> MCS(len1 + 1, vector<int>(len2 + 1, 0));
		for (i = 1; i <= len1; i++){
			for (j = 1; j <= len2; j++){
				if (s1[i - 1] == s2[j - 1]){
					MCS[i][j] = MCS[i - 1][j - 1] + 1;
				}
				if (MCS[i][j] > max){
					max = MCS[i][j];
					start = i - max;
				}
			}
		}
		cout << s1.substr(start, max) << endl;
	}
	return 0;
}
