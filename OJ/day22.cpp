//找一串字符串中只出现一次的字符，找不到返回-1
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
				//find和rfind返回找到的下标，如果有两个以上那么两者找到的位置是不同的
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

//小易经常沉迷于网络游戏，打怪升级游戏
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
	int monsterNum = 0;    //怪物数量
	int preAbility = 0;    //初始能力
	while (cin >> monsterNum >> preAbility){
		int nowAbility = preAbility;    //当前能力
		vector<int> defence(monsterNum);    //怪物防御力
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