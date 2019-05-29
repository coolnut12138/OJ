链接：https://www.nowcoder.com/questionTerminal/e1bb714eb9924188a0d5a6df2216a3d1
来源：牛客网

对于一个给定的井字棋棋盘，请设计一个高效算法判断当前玩家是否获胜。

给定一个二维数组board，代表当前棋盘，其中元素为1的代表是当前玩家的棋子，为0表示没有棋子，为 - 1代表是对方玩家的棋子。

测试样例：
[[1, 0, 1], [1, -1, -1], [1, -1, 0]]
返回：true
class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		// write code here
		if (board[0][0] + board[1][1] + board[2][2] == 3){
			return true;
		}
		if (board[0][2] + board[1][1] + board[2][0] == 3){
			return true;
		}
		for (int i = 0; i < 3; i++){
			if (board[0][i] + board[1][i] + board[2][i] == 3){
				return true;
			}
			if (board[i][0] + board[i][1] + board[i][2] == 3){
				return true;
			}
		}
		return false;
	}
};

https://www.nowcoder.com/questionTerminal/52d382c2a7164767bca2064c1c9d5361?pos=53&orderByHotValue=0
密码按如下规则进行计分，并根据不同的得分为密码进行安全等级划分。
#include <iostream>
#include <string>
using namespace std;

void Test(string& code)
{
	int score = 0;
	//密码长度
	if (code.size() <= 4){
		score = 5;
	}
	else if (code.size() >= 5 && code.size() <= 7){
		score = 10;
	}
	else if (code.size() >= 8){
		score = 25;
	}
	//字母和数字和字符
	int bigcount = 0;//大写字母计数
	int litcount = 0;//小写字母计数
	int numcount = 0;//数字计数
	int chrcount = 0;//字符计数
	auto it = code.begin();
	while (it != code.end()){
		if ((*it) <= 'z' && (*it) >= 'a'){
			litcount++;
		}
		else if ((*it) <= 'Z' && (*it) >= 'A'){
			bigcount++;
		}
		else if ((*it) >= '0' && (*it) <= '9'){
			numcount++;
		}
		else{
			chrcount++;
		}
		++it;
	}
	if ((litcount + bigcount) == 0){
		score += 0;
	}
	else if (litcount == code.size() || bigcount == code.size()){
		score += 10;
	}
	else if (litcount != code.size() && bigcount != code.size()){
		score += 20;
	}

	if (numcount == 0){
		score += 0;
	}
	else if (numcount == 1){
		score += 10;
	}
	else if (numcount > 1){
		score += 20;
	}

	if (chrcount == 0){
		score += 0;
	}
	else if (chrcount == 1){
		score += 10;
	}
	else if (chrcount > 1){
		score += 25;
	}

	if (numcount != 0 && chrcount != 0){
		score += 2;
	}
	if (numcount != 0 && chrcount != 0 && (bigcount + litcount) != 0){
		score += 3;
	}
	if (numcount != 0 && chrcount != 0 && bigcount != 0 && litcount != 0){
		score += 5;
	}
	if (score >= 90){
		cout << "VERY_SECURE" << endl;
	}
	else if (score >= 80 && score < 90){
		cout << "SECURE" << endl;
	}
	else if (score >= 70 && score < 80){
		cout << "VERY_STRONG" << endl;
	}
	else if (score >= 60 && score < 70){
		cout << "STRONG" << endl;
	}
	else if (score >= 50 && score < 60){
		cout << "AVERAGE" << endl;
	}
	else if (score >= 25 && score < 50){
		cout << "WEAK" << endl;
	}
	else if (score >= 0 && score < 25){
		cout << "VERY_WEAK" << endl;
	}
}

int main()
{
	string code;
	while (cin >> code){
		Test(code);
	}
	system("pause");
	return 0;
}