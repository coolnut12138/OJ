#define _CRT_SECURE_NO_WARNINGS 1
//杨辉三角
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ret;
		ret.resize(numRows);
		//初始化每一行
		for (int i = 0; i < numRows; i++){
			ret[i].resize(i + 1, 0);

			//每一行第一列和最后一列都是1
			ret[i][0] = 1;
			ret[i][i] = 1;
		}

		//计算中间的值
		for (int i = 0; i < ret.size(); i++){
			for (int j = 0; j < ret[i].size(); j++){
				if (0 == ret[i][j]){
					ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
				}
			}
		}

		return ret;
	}
};


//返回杨辉三角的第k行
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<vector<int>> ret;    //存放整个杨辉三角
		ret.resize(rowIndex + 1);   //注意此处下标是从0开始，所以要多给一个空间
		vector<int> res(rowIndex + 1);  //存放第k行
		for (int i = 0; i <= rowIndex; i++){
			ret[i].resize(i + 1, 0);

			ret[i][0] = 1;
			ret[i][i] = 1;
		}

		for (int i = 0; i < ret.size(); i++){
			for (int j = 0; j < ret[i].size(); j++){
				if (0 == ret[i][j]){
					ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
				}
			}
		}

		for (int i = 0; i <= rowIndex; i++){
			res[i] = ret[rowIndex][i];
		}

		return res;
	}
};