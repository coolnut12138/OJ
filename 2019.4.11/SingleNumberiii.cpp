#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

//������num�Ķ����Ʊ�ʾ�ҵ����ұ���1��λ
unsigned int FindFirstBitIs1(int num){
	int indexBit = 0;
	while ((0 == (num & 1)) && (indexBit < 32)){
		num = num >> 1;
		++indexBit;
	}
	return indexBit;
}

//�ж�num���ұ������indexBitλ�ǲ���1
bool isBit1(int num, unsigned int indexBit){
	num = num >> indexBit;
	return (num & 1);
}

vector<int> singleNumber(vector<int>& nums) {
	//�Ƚ���������򣬵õ��Ľ�����ǳ���һ�ε��������������
	int tmp = 0;
	for (auto e : nums){
		tmp ^= e;
	}

	unsigned int indexIs1 = FindFirstBitIs1(tmp);

	int ret1 = 0, ret2 = 0;
	for (auto e : nums){
		if (isBit1(e, indexIs1)){
			ret1 ^= e;
		}
		else{
			ret2 ^= e;
		}
	}
	vector<int> ret;
	ret.push_back(ret1);
	ret.push_back(ret2);
	return ret;
}

int main()
{
	vector<int> nums(6);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(4);
	vector<int> ret = singleNumber(nums);
	vector<int>::const_iterator rit = ret.begin();
	while (rit != ret.end()){
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	system("pause");
	return 0;
}