���ӣ�https://www.nowcoder.com/questionTerminal/286af664b17243deb745f69138f8a800?orderByHotValue=1&page=4&onlyReference=false
��Դ��ţ����

NowCoderÿ��Ҫ��������ʼ����������������ռ����б��У���ʱ��ֻ�Ǳ����͡�����Ϊ��Щ���͵��ʼ���Ҫ�Ա��Լ����ռ����б�����ʼ��ͣ������Ҫ���˵���Щ��Ҫ���ʼ������ȴ�����Ҫ���ʼ���
���ڸ���һ�������б������ж�Ŀ���û��Ƿ��ڳ����б��С�

�������� :
�����ж������ݣ�ÿ�����������С�

��һ�г����б�����֮����һ�����Ÿ�������������а����ո�򶺺ţ�������������˫������ܳ��Ȳ�����512���ַ���

�ڶ���ֻ����һ���������Ǵ����ҵ��û������֣�����Ҫ��ȫƥ�䣩�����Ȳ�����16���ַ���
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string name;	//�����б�
	string name2;	//Ҫƥ�������
	while (getline(cin, name)){
		int flag = -1;
		getline(cin, name2);
		for (size_t i = 0; i < name.size(); i++){
			string tmp;
			if (name[i] == '"'){	//�ӵ�һ��˫���ſ�ʼ
				++i;
				while (i < name.size() && name[i] != '"'){	//�����һ��˫���Ž���
					tmp += name[i];
					++i;
				}
				if (tmp == name2){	//���tmp����name2�ͱ�ʾname2�ڳ����б���
					flag = 1;
				}
			}
			else if (name[i] != ','){
				while (i < name.size() && name[i] != ','){
					tmp += name[i];
					++i;
				}
				if (tmp == name2){
					flag = 1;
				}
			}
		}
		if (flag == 1){
			cout << "Ignore" << endl;
		}
		else{
			cout << "Important!" << endl;
		}
	}
	return 0;
}