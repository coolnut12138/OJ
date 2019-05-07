#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <vector>
using namespace std;
//leetcode448.找到所有数组中消失的数字
//思路：遍历整个数组，将数组中的数组元素对应下标的值改为负值，然后再遍历整个数组，不为负数的下标就是消失的数据
//比如3，4，2，1，3，2，首先第一个数是3，就将下标为2的元素改为负值，第二个数是4，就将下标为3的元素改为负值，以此类推
//注意修改值的时候要使用绝对值防止之前该过的数据影响到后面的修改
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