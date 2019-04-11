#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int bitarr[32] = { 0 };   //存放为1的每一位
		for (int i = 0; i < nums.size(); i++){
			for (int j = 0; j < 32; j++){
				int tmp = nums[i] >> j & 1;   //判断每一位是否为1
				if (tmp == 1){
					bitarr[32 - j - 1]++;   //将为1的二进制位+1；
				}
			}
		}

		long long ret = 0;
		//将所有位%3，剩下的就是只出现一次的数
		for (int i = 0; i < 32; i++){
			bitarr[i] %= 3;
		}

		long long er = 1;
		//将每一位组成一个整数
		for (int i = 0; i < 32; i++){
			ret += bitarr[32 - i - 1] * er;
			er *= 2;
		}

		return ret;
	}
};