#define _CRT_SECURE_NO_WARNINGS 1
//�������
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ret;
		ret.resize(numRows);
		//��ʼ��ÿһ��
		for (int i = 0; i < numRows; i++){
			ret[i].resize(i + 1, 0);

			//ÿһ�е�һ�к����һ�ж���1
			ret[i][0] = 1;
			ret[i][i] = 1;
		}

		//�����м��ֵ
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


//����������ǵĵ�k��
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<vector<int>> ret;    //��������������
		ret.resize(rowIndex + 1);   //ע��˴��±��Ǵ�0��ʼ������Ҫ���һ���ռ�
		vector<int> res(rowIndex + 1);  //��ŵ�k��
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