#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <vector>
using namespace std;
//leetcode448.�ҵ�������������ʧ������
//˼·�������������飬�������е�����Ԫ�ض�Ӧ�±��ֵ��Ϊ��ֵ��Ȼ���ٱ����������飬��Ϊ�������±������ʧ������
//����3��4��2��1��3��2�����ȵ�һ������3���ͽ��±�Ϊ2��Ԫ�ظ�Ϊ��ֵ���ڶ�������4���ͽ��±�Ϊ3��Ԫ�ظ�Ϊ��ֵ���Դ�����
//ע���޸�ֵ��ʱ��Ҫʹ�þ���ֵ��ֹ֮ǰ�ù�������Ӱ�쵽������޸�
vector<int> findDisappearedNumbers(vector<int>& nums) {
	vector<int> ret;
	for (int i = 0; i < nums.size(); ++i){
		nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
	}

	for (int i = 0; i < nums.size(); ++i){
		if (nums[i] > 0){
			ret.push_back(i + 1);
		}
	}
	return ret;
}

int main()
{
	vector<int> a;
	a.push_back(4);
	a.push_back(3);
	a.push_back(2);
	a.push_back(7);
	a.push_back(8);
	a.push_back(2);
	a.push_back(3);
	a.push_back(1);
	vector<int> ret = findDisappearedNumbers(a);
	//auto it = ret.end() - 1;
	//cout << *it << endl;
	for (auto e : ret){
		cout << e << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}