#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//ţ�ͣ�ɾ�����ִ������������ܳ���һ���Ԫ��
//˼·��1��������Ȼ��һ��һ����������ж��Ƿ���ȣ������ȼ����� 1
//     2��������ȣ���˵���Ѿ�����ȵ�Ԫ�������ˣ��жϼ����Ƿ���������һ�룬����������ҵ�������û�ҵ�
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
	int count = 0;    //���ڼ���Ԫ�س��ֵĴ���
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