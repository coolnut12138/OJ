#define _CRT_SECURE_NO_WARNINGS 1
//牛客。连续子数组的最大和
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int sum = array[0];
		int ret = array[0];
		for (int i = 1; i < array.size(); i++){
			sum = max(sum + array[i], array[i]);    //取当前元素和当前元素之前所有元素之和的最大值
			ret = max(sum, ret);    //ret中存储所有 sum 中最大的值，也就是最终的最大连续子序列的和
		}
		return ret;
	}
};