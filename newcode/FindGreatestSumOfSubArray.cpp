#define _CRT_SECURE_NO_WARNINGS 1
//ţ�͡����������������
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int sum = array[0];
		int ret = array[0];
		for (int i = 1; i < array.size(); i++){
			sum = max(sum + array[i], array[i]);    //ȡ��ǰԪ�غ͵�ǰԪ��֮ǰ����Ԫ��֮�͵����ֵ
			ret = max(sum, ret);    //ret�д洢���� sum ������ֵ��Ҳ�������յ�������������еĺ�
		}
		return ret;
	}
};