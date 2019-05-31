//��ָoffer ˳ʱ���ӡ��ά����
class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		int row = matrix.size();    //����
		int col = matrix[0].size();    //����
		vector<int> res;
		if (row == 0 || col == 0){
			return res;
		}
		int left = 0, right = col - 1;
		int up = 0, down = row - 1;
		while (left <= right && up <= down){
			for (int i = left; i <= right; i++){
				res.push_back(matrix[up][i]);    //����
			}
			if (up < down){
				for (int i = up + 1; i <= down; i++){
					res.push_back(matrix[i][right]);    //����
				}
			}
			if (up < down && right > left){
				for (int i = right - 1; i >= left; i--){
					res.push_back(matrix[down][i]);//����
				}
			}
			if (up < down - 1 && left < right){
				for (int i = down - 1; i >= up + 1; i--){
					res.push_back(matrix[i][left]);//����
				}
			}
			left++; up++; right--; down--;
		}
		return res;
	}
};