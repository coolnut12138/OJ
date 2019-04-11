#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int bitarr[32] = { 0 };   //���Ϊ1��ÿһλ
		for (int i = 0; i < nums.size(); i++){
			for (int j = 0; j < 32; j++){
				int tmp = nums[i] >> j & 1;   //�ж�ÿһλ�Ƿ�Ϊ1
				if (tmp == 1){
					bitarr[32 - j - 1]++;   //��Ϊ1�Ķ�����λ+1��
				}
			}
		}

		long long ret = 0;
		//������λ%3��ʣ�µľ���ֻ����һ�ε���
		for (int i = 0; i < 32; i++){
			bitarr[i] %= 3;
		}

		long long er = 1;
		//��ÿһλ���һ������
		for (int i = 0; i < 32; i++){
			ret += bitarr[32 - i - 1] * er;
			er *= 2;
		}

		return ret;
	}
};