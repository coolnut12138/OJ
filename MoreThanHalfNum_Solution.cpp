#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//牛客，删除出现次数超过数组总长的一半的元素
//思路：1、先排序，然后一个一个往后遍历判断是否相等，如果相等计数加 1
//     2、如果不等，则说明已经把相等的元素走完了，判断计数是否大于数组的一半，如果大于则找到，否则没找到
int MoreThanHalfNum_Solution(vector<int> numbers) {
	if (0 == numbers.size()){
		return 0;
	}
	if (1 == numbers.size()){
		return numbers[0];
	}
	sort(numbers.begin(), numbers.end());
	int halfnumber = numbers.size() / 2;
	int firstElement = numbers[0];
	int count = 0;    //用于计算元素出现的次数
	for (int i = 0; i < numbers.size(); i++){
		if (firstElement == numbers[i]){
			count++;
		}
		else{
			if (count > halfnumber){
				return firstElement;
			}
			firstElement = numbers[i];
			count = 1;
		}
	}

	if (count > halfnumber){
		return firstElement;
	}
	else{
		return 0;
	}
}

int main()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	num.push_back(2);
	num.push_back(2);
	num.push_back(2);
	num.push_back(5);
	num.push_back(4);
	num.push_back(2);
	int ret = MoreThanHalfNum_Solution(num);
	
	cout << ret << endl;
	system("pause");
	return 0;
}