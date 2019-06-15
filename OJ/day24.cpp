//年终奖
class Bonus {
public:
	int getMost(vector<vector<int> > board) {
		// write code here
		for (int i = 0; i < board.size(); i++){
			for (int j = 0; j < board[0].size(); j++){
				if (i == 0 && j != 0){
					//只能从左边来，上面没有元素
					board[i][j] += board[i][j - 1];
				}
				else if (i != 0 && j == 0){
					//只能从上面来，左面没有元素
					board[i][j] += board[i - 1][j];
				}
				else if (i != 0 && j != 0){
					//当走到中间时，就要看是左边的元素大还是上面的元素大，加大的元素。
					board[i][j] += (board[i - 1][j] > board[i][j - 1] ? board[i - 1][j] : board[i][j - 1]);
				}
			}
		}
		//最后一个元素就是最大的值
		return board[board.size() - 1][board[0].size() - 1];
	}
};


//迷宫
#include <iostream>
#include <vector>
using namespace std;
int row, col;    //行列
vector<vector<int>> maze;    //迷宫
vector<vector<int>> path_temp;    //当前路径
vector<vector<int>> path_best;    //最佳路径

void GetPath(int i, int j)
{
	maze[i][j] = 1;    //走过的路标记以下
	path_temp.push_back({ i, j });    //将当前结点放入路径中

	//判断是否走到终点
	if (i == row - 1 && j == col - 1){
		//更新最佳路径
		if (path_best.empty() || path_temp.size() < path_best.size()){
			path_best = path_temp;
		}
	}

	if (i - 1 >= 0 && maze[i - 1][j] == 0){
		//向上是否能走
		GetPath(i - 1, j);
	}
	if (i + 1 < row && maze[i + 1][j] == 0){
		//能否向下走
		GetPath(i + 1, j);
	}
	if (j - 1 >= 0 && maze[i][j - 1] == 0){
		//能否向左走
		GetPath(i, j - 1);
	}
	if (j + 1 < col && maze[i][j + 1] == 0){
		//能否向右走
		GetPath(i, j + 1);
	}

	//走到这代表上下左右都走不了了。将回溯向前
	maze[i][j] = 0;    //将标记取消
	path_temp.pop_back();    //将路径倒退一步
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