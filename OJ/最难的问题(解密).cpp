nowcoder�����ڳ���Σ�պ���ı���������������ǽ���д��ĸ�޸�Ϊ����ĸ�ĵ���������ڸ����룬�ý���
// write your code here cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string code;    //����
	while (getline(cin, code)){
		string text = "";    //����
		for (size_t i = 0; i < code.size(); i++){
			if (code[i] >= 'A' && code[i] <= 'Z'){
				code[i] -= 5;
				if (code[i] < 65){    //���Խ��ʹӺ��濪ʼ��
					code[i] = 'Z' - ('A' - code[i]) + 1;
				}
				text += code[i];
			}
			else{
				text += code[i];
			}
		}
		cout << text << endl;
	}
	return 0;
}



//���Ӹ�������ʽ�ֽ�
���ӣ�https://www.nowcoder.com/questionTerminal/e8fb8f89f5d147ec92fd8ecfefe89b0d
��Դ��ţ����
һ�����������Էֽ��һ����������Ļ�������36 = 2 * 2 * 3 * 3��������2��3�������ӡ�NowCoder������о����Ӹ����ķֲ����ɣ����ڸ���һϵ������������ϣ���㿪��һ���������ÿ�������������Ӹ�����

�������� :
��������������ݡ�
ÿ�����ݽ���һ������n(2��n��100000)��
// write your code here cpp
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, count;
	while (cin >> n){
		count = 0;
		for (int i = 2; i < sqrt(n); i++){
			if (n % i == 0){
				while (n % i == 0){
					n /= i;
				}
				count++;
			}
		}
		if (n != 1){
			count++;
		}
		cout << count << endl;
	}
	return 0;
}