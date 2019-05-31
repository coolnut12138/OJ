//剑指offer 顺时针打印二维矩阵
class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		int row = matrix.size();    //行数
		int col = matrix[0].size();    //列数
		vector<int> res;
		if (row == 0 || col == 0){
			return res;
		}
		int left = 0, right = col - 1;
		int up = 0, down = row - 1;
		while (left <= right && up <= down){
			for (int i = left; i <= right; i++){
				res.push_back(matrix[up][i]);    //向右
			}
			if (up < down){
				for (int i = up + 1; i <= down; i++){
					res.push_back(matrix[i][right]);    //向下
				}
			}
			if (up < down && right > left){
				for (int i = right - 1; i >= left; i--){
					res.push_back(matrix[down][i]);//向左
				}
			}
			if (up < down - 1 && left < right){
				for (int i = down - 1; i >= up + 1; i--){
					res.push_back(matrix[i][left]);//向上
				}
			}
			left++; up++; right--; down--;
		}
		return res;
	}
};