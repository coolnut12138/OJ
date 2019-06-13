//��һ���ַ�����ֻ����һ�ε��ַ����Ҳ�������-1
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	while (cin >> str){
		size_t i;
		for (i = 0; i < str.size(); i++){
			if (str.find(str[i]) == str.rfind(str[i])){
				//find��rfind�����ҵ����±꣬���������������ô�����ҵ���λ���ǲ�ͬ��
				cout << str[i] << endl;
				break;
			}
		}
		if (i == str.size()){
			cout << "-1" << endl;
		}
	}
	return 0;
}

//С�׾���������������Ϸ�����������Ϸ
#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
	int tmp = b;
	while (a % b != 0){
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return tmp;
}

int main()
{
	int monsterNum = 0;    //��������
	int preAbility = 0;    //��ʼ����
	while (cin >> monsterNum >> preAbility){
		int nowAbility = preAbility;    //��ǰ����
		vector<int> defence(monsterNum);    //���������
		for (int i = 0; i < monsterNum; i++){
			cin >> defence[i];
		}
		for (int i = 0; i < monsterNum; i++){
			if (defence[i] <= nowAbility){
				nowAbility += defence[i];
			}
			else{
				nowAbility += gcd(nowAbility, defence[i]);
			}
		}
		cout << nowAbility << endl;
	}
	return 0;
}