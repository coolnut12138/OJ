#define _CRT_SECURE_NO_WARNINGS 1
//leetcode136.只出现一次的数字
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int value = 0;
		for (auto num : nums){
			value ^= num;
		}
		return value;
	}
};