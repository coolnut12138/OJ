���ӣ�https://www.nowcoder.com/questionTerminal/ceb89f19187b4de3997d9cdef2d551e8?source=relative
��Դ��ţ����
��ͼ��һ���绰�ľŹ�����������һ�����ֶ�ӦһЩ��ĸ������ڹ�����ҵϲ���ѵ绰������Ƴ����Լ���˾�������Ӧ�����繫˾��Help Desk������4357����Ϊ4��ӦH��3��ӦE��5��ӦL��7��ӦP�����4357����HELP��ͬ��TUT - GLOP�ʹ���888 - 4567��310 - GINO����310 - 4466��
NowCoder�ս������󣬲���ϰ��������������ʽ�����ڸ���һ���绰�����б��������ת����������ʽ�ĺ��룬��ȥ���ظ��Ĳ��֡�
#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main()
{
	int n;
	map<char, char> mp;
	mp['A'] = '2';
	mp['B'] = '2';
	mp['C'] = '2';

	mp['D'] = '3';
	mp['E'] = '3';
	mp['F'] = '3';

	mp['G'] = '4';
	mp['H'] = '4';
	mp['I'] = '4';

	mp['J'] = '5';
	mp['K'] = '5';
	mp['L'] = '5';

	mp['M'] = '6';
	mp['N'] = '6';
	mp['O'] = '6';

	mp['P'] = '7';
	mp['Q'] = '7';
	mp['R'] = '7';
	mp['S'] = '7';

	mp['T'] = '8';
	mp['U'] = '8';
	mp['V'] = '8';

	mp['W'] = '9';
	mp['X'] = '9';
	mp['Y'] = '9';
	mp['Z'] = '9';

	while (cin >> n){
		string s;
		set<string> ret;
		for (int i = 0; i < n; ++i){
			cin >> s;
			//ȥ��"-"
			string tmp = "";
			for (size_t i = 0; i < s.size(); ++i){
				if (s[i] != '-'){
					tmp += s[i];
				}
			}
			//����ĸת��Ϊ����
			for (size_t i = 0; i < tmp.size(); ++i){
				if (tmp[i] >= 'A' && tmp[i] <= 'Z'){
					tmp[i] = mp[tmp[i]];
				}
			}
			//��ת���õ��ַ���ת��Ϊ��ȷ��ʽ
			tmp.insert(tmp.begin() + 3, '-');
			//����set��
			ret.insert(tmp);
		}

		for (auto &e : ret){
			cout << e << endl;
		}
		cout << endl;
	}
	return 0;
}