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
