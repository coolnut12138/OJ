���ӣ�https://www.nowcoder.com/questionTerminal/e1bb714eb9924188a0d5a6df2216a3d1
��Դ��ţ����

����һ�������ľ��������̣������һ����Ч�㷨�жϵ�ǰ����Ƿ��ʤ��

����һ����ά����board������ǰ���̣�����Ԫ��Ϊ1�Ĵ����ǵ�ǰ��ҵ����ӣ�Ϊ0��ʾû�����ӣ�Ϊ - 1�����ǶԷ���ҵ����ӡ�

����������
[[1, 0, 1], [1, -1, -1], [1, -1, 0]]
���أ�true
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
���밴���¹�����мƷ֣������ݲ�ͬ�ĵ÷�Ϊ������а�ȫ�ȼ����֡�
#include <iostream>
#include <string>
using namespace std;

void Test(string& code)
{
	int score = 0;
	//���볤��
	if (code.size() <= 4){
		score = 5;
	}
	else if (code.size() >= 5 && code.size() <= 7){
		score = 10;
	}
	else if (code.size() >= 8){
		score = 25;
	}
	//��ĸ�����ֺ��ַ�
	int bigcount = 0;//��д��ĸ����
	int litcount = 0;//Сд��ĸ����
	int numcount = 0;//���ּ���
	int chrcount = 0;//�ַ�����
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