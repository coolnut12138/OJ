//һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж������������Ⱥ����ͬ�㲻ͬ�Ľ������
//̨����  ����
//  1      1
//  2      2
//  3      3
//  4      5
//  5      8
//���͵�쳲���������

class Solution {
public:
	int jumpFloor(int number) {
		if (number == 1){
			return 1;
		}
		if (number == 2){
			return 2;
		}

		int step1 = 1;
		int step2 = 2;
		int sum = 0;
		while (number > 2){
			sum = step1 + step2;
			step1 = step2;
			step2 = sum;
			number--;
		}
		return sum;
	}
};