���ӣ�https://www.nowcoder.com/questionTerminal/81544a4989df4109b33c2d65037c5836?toCommentId=3247302
��Դ��ţ����
���ַ����е����е��ʽ��е��š�
˵����
1��ÿ����������26����д��СдӢ����ĸ���ɣ�
2���ǹ��ɵ��ʵ��ַ�����Ϊ���ʼ������
3��Ҫ���ź�ĵ��ʼ������һ���ո��ʾ�����ԭ�ַ��������ڵ��ʼ��ж�������ʱ������ת����Ҳֻ�������һ���ո�������
4��ÿ�������20����ĸ��
//˼·���Ƚ������ַ�������Ȼ��������ʵ���
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str)){
		//���ַ������巴ת
		reverse(str.begin(), str.end());
		string tmp = "";
		int count = 0;    //�ո��־λ
		//���ַ����в�����ĸ���ַ��滻Ϊ�ո�
		for (size_t i = 0; i < str.size(); ++i){
			if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z'){
				tmp += str[i];
				count = 0;
			}
			else{
				if (count == 0){    //�ո�������0��ֻҪһ���ո�
					tmp += ' ';
				}
				count++;
			}
		}
		auto pos = tmp.begin();
		auto cur = tmp.begin();
		//��תÿһ������
		while (cur != tmp.end()){
			while (cur != tmp.end() && *cur != ' '){
				cur++;
			}
			reverse(pos, cur);
			if (cur != tmp.end()){
				cur++;
			}
			pos = cur;
		}

		//�����һ���ַ��ǿո��ɾ����һ���ַ�
		if (tmp[0] == ' '){
			tmp = tmp.substr(1);
		}
		//������һ���ַ��ǿո��ɾ�����һ���ַ�
		if (tmp[tmp.size() - 1] == ' '){
			tmp = tmp.substr(0, tmp.size() - 1);
		}
		cout << tmp << endl;
	}
	return 0;
}