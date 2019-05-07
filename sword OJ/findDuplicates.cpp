#define _CRT_SECURE_NO_WARNINGS 1
//leetcode442.�����������ظ�������
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> findDuplicates(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<int> ret;
	if (nums.empty()){
		return ret;
	}
	size_t size = nums.size();
	//forѭ����ֹͣ������size - 1����Ϊ��vector���һ��Ԫ��ʱ++i��Խ��
	for (size_t i = 0; i < size - 1; ++i){
		if (nums[i] != nums[i + 1]){
			continue;
		}
		else if (nums[i] == nums[i + 1]){
			ret.push_back(nums[i]);
			++i;
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
	vector<int> ret = findDuplicates(a);
	//auto it = ret.end() - 1;
	//cout << *it << endl;
	for (auto e : ret){
		cout << e << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}