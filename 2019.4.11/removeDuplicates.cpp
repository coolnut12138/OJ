//#define _CRT_SECURE_NO_WARNINGS 1
//
////leetcode26.删除排序数组中的重复项
//class Solution {
//public:
//	int removeDuplicates(vector<int>& nums) {
//		if (0 == nums.size()){
//			return 0;
//		}
//		//双指针遍历法
//		int ret = 0;
//		int len = 1;
//		int i = 1;
//		while (i < nums.size()){
//			if (nums[ret] == nums[i]){
//				//相等就删除第二个相同的元素。
//				nums.erase(nums.begin() + i);
//				continue;
//			}
//			else{
//				//不等于两个都向后走
//				ret = i++;
//				++len;
//			}
//		}
//		return len;
//	}
//};