//���ս�
class Bonus {
public:
	int getMost(vector<vector<int> > board) {
		// write code here
		for (int i = 0; i < board.size(); i++){
			for (int j = 0; j < board[0].size(); j++){
				if (i == 0 && j != 0){
					//ֻ�ܴ������������û��Ԫ��
					board[i][j] += board[i][j - 1];
				}
				else if (i != 0 && j == 0){
					//ֻ�ܴ�������������û��Ԫ��
					board[i][j] += board[i - 1][j];
				}
				else if (i != 0 && j != 0){
					//���ߵ��м�ʱ����Ҫ������ߵ�Ԫ�ش��������Ԫ�ش󣬼Ӵ��Ԫ�ء�
					board[i][j] += (board[i - 1][j] > board[i][j - 1] ? board[i - 1][j] : board[i][j - 1]);
				}
			}
		}
		//���һ��Ԫ�ؾ�������ֵ
		return board[board.size() - 1][board[0].size() - 1];
	}
};


//�Թ�
#include <iostream>
#include <vector>
using namespace std;
int row, col;    //����
vector<vector<int>> maze;    //�Թ�
vector<vector<int>> path_temp;    //��ǰ·��
vector<vector<int>> path_best;    //���·��

void GetPath(int i, int j)
{
	maze[i][j] = 1;    //�߹���·�������
	path_temp.push_back({ i, j });    //����ǰ������·����

	//�ж��Ƿ��ߵ��յ�
	if (i == row - 1 && j == col - 1){
		//�������·��
		if (path_best.empty() || path_temp.size() < path_best.size()){
			path_best = path_temp;
		}
	}

	if (i - 1 >= 0 && maze[i - 1][j] == 0){
		//�����Ƿ�����
		GetPath(i - 1, j);
	}
	if (i + 1 < row && maze[i + 1][j] == 0){
		//�ܷ�������
		GetPath(i + 1, j);
	}
	if (j - 1 >= 0 && maze[i][j - 1] == 0){
		//�ܷ�������
		GetPath(i, j - 1);
	}
	if (j + 1 < col && maze[i][j + 1] == 0){
		//�ܷ�������
		GetPath(i, j + 1);
	}

	//�ߵ�������������Ҷ��߲����ˡ���������ǰ
	maze[i][j] = 0;    //�����ȡ��
	path_temp.pop_back();    //��·������һ��
}

int main()
{
	while (cin >> row >> col){
		path_temp.clear();
		path_best.clear();
		maze.resize(row);
		for (int i = 0; i < row; i++){
			maze[i].resize(col);
			for (int j = 0; j < col; j++){
				cin >> maze[i][j];
			}
		}
		GetPath(0, 0);
		for (auto &e : path_best){
			cout << "(" << e[0] << "," << e[1] << ")" << endl;
		}
	}
	return 0;
}