//#define _CRT_SECURE_NO_WARNINGS 1
//
////leetcode26.ɾ�����������е��ظ���
//class Solution {
//public:
//	int removeDuplicates(vector<int>& nums) {
//		if (0 == nums.size()){
//			return 0;
//		}
//		//˫ָ�������
//		int ret = 0;
//		int len = 1;
//		int i = 1;
//		while (i < nums.size()){
//			if (nums[ret] == nums[i]){
//				//��Ⱦ�ɾ���ڶ�����ͬ��Ԫ�ء�
//				nums.erase(nums.begin() + i);
//				continue;
//			}
//			else{
//				//�����������������
//				ret = i++;
//				++len;
//			}
//		}
//		return len;
//	}
//};