//����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
//�ⷨһ
class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		for (int i = 0; i < 32; i++){
			if (n & 1 == 1){
				count++;
			}
			n >>= 1;
		}
		return count;
	}
};

//���Ž�
class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		while (n){
			n = n & (n - 1);
			count++;
		}
		return count;
	}
};