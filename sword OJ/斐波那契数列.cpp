//쳲���������
class Solution {
public:
	int Fibonacci(int n) {
		/*�ݹ�
		if(n == 0){
		return 0;
		}

		if(n >= 1 && n <= 2){
		return 1;
		}
		else{
		return Fibonacci(n - 1) + Fibonacci(n - 2);
		}*/
		//�ǵݹ�=-----��̬�滮
		class Solution {
		public:
			int climbStairs(int n) {
				if (n < 1){
					return 0;
				}
				if (n == 1){
					return 1;
				}
				if (n == 2){
					return 2;
				}
				//����һ�����齫���ִ洢���������������Ŀռ临�Ӷȱ�Ϊ��O(n)
				int *record = new int[n + 1];
				record[0] = 1;
				record[1] = 1;
				for (int i = 2; i <= n; i++){
					record[i] = record[i - 1] + record[i - 2];
				}
				return record[n];
				delete[] record;

			}
		};

		//�����ַ�������̬�滮�����ô������飬��Ϊ��� n ��ֻ��Ҫ�� n - 1 �� �� �� n - 2 ���
		if (n == 0){
			return 0;
		}
		int a = 1;
		int b = 1;
		int ret = 1;
		for (int i = 0; i <= n - 2; i++){
			ret = a + b;
			a = b;
			b = ret;
		}
		return ret;
	}
};