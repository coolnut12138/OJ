//��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
class Solution {
public:
	class Sum    //ʵ��һ���ڲ���
	{
	public:		//�ڲ���Ĺ��캯��һ����Ϊpublic����Ϊclass��Ĭ����private��
		Sum()
		{
			sum += i;
			++i;
		}
	};
	int Sum_Solution(int n) {
		sum = 0;
		i = 1;
		Sum arr[n];    //ͨ�������ڲ��๹�캯��
		return sum;
	}
private:
	static int sum;
	static int i;    //ʹ�þ�̬���������ۼ�
};

int Solution::sum = 0;
int Solution::i = 1;