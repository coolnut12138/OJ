���⣺��Ҫ�� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K | �������ƣ� ����
����Ҫ��������С����һ��W*H��������ӣ�������б��Ϊ0~H - 1��������б��Ϊ0~W - 1��ÿ������������Է�һ�鵰�⣬�������鵰���ŷ����þ��벻�ܵ�
��2��
����������������(x1, y1), (x2, y2)��ŷ����þ���Ϊ:
((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) ������ƽ����
С����֪�������ԷŶ��ٿ鵰������������
����������ÿ������������񳤿�W, H���ÿո�ָ�.(1 �� W��H �� 1000)
�������:���һ�������Էŵĵ�����
	 3 2
	 4

#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int W, H;
	cin >> W >> H;
	int ret = 0;
	if (0 == W % 4 || 0 == H % 4){
		ret = W * H / 2;
	}
	else if (0 == W % 2 && 0 == H % 2){
		ret = W * H / 2 + 2;
	}
	else{
		ret = W * H / 2 + 1;
	} 
	cout << ret << endl;
	return 0;
}


�����ַ���ת������������һ���ַ���ת����һ������(ʵ��Integer.valueOf(string)�Ĺ��ܣ�����string����������Ҫ��ʱ����0)��Ҫ����ʹ���ַ���ת�������Ŀ�
������ ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0��
��������������һ���ַ���, ����������ĸ����, ����Ϊ��
�������������ǺϷ�����ֵ�����򷵻ظ����֣����򷵻�0
+ 2147483647
1a33

2147483647
0
class Solution {
public:
	int StrToInt(string str) {
		auto sit = str.begin();
		long long num = 0;
		int flag = 1;
		if (*sit == '+'){
			++sit;
		}
		else if (*sit == '-'){
			flag = -1;
			++sit;
		} 
		while(sit != str.end()){
			if (*sit >= '0' && *sit <= '9'){
				num = num * 10 + (*sit - '0');
				++sit;
			}
			else{
				num = 0;
				break;
			}
		} 
		return num * flag;
	}
};