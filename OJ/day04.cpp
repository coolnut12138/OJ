��Ŀ��A, B, C�������Ǻ�����, ÿ�������ﶼ��һЩ�ǹ�, ���ǲ�֪������ÿ�������Ͼ����ж��ٸ��ǹ�, ��������֪������
����Ϣ��A - B, B - C, A + B, B + C.���ĸ���ֵ.ÿ����ĸ����ÿ������ӵ�е��ǹ���.������Ҫͨ�����ĸ���ֵ�����ÿ��
�������ж��ٸ��ǹ�, ��A, B, C�����ﱣ֤���ֻ��һ������A, B, C������������������

����������
����Ϊһ�У�һ��4���������ֱ�ΪA - B��B - C��A + B��B + C���ÿո������ ��Χ���� - 30��30֮��(������)��
���������
���Ϊһ�У�����������������A��B��C��˳�����A��B��C���ÿո��������ĩ�޿ո� �������������������A��B��C�������No
ʾ��1 :
���룺1 - 2 3 4

�����2 1 3

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int A, B, C;
	vector<int> v;
	int n;
	while (cin >> n)
		v.push_back(n);
	A = (v[0] + v[2]) / 2;
	B = (v[1] + v[3]) / 2;
	C = v[3] - B;
	if ((A - B == v[0]) && (B - C == v[1]) && (A + B == v[2]) && (B + C == v[3])){
		cout << A << " " << B << " " << C << endl;
	}
	else{
		cout << "No" << endl;
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int A = (a + c) / 2;
	int C = (d - b) / 2;
	int B1 = (c - a) / 2;
	int B2 = (b + d) / 2;

	if (B1 != B2){
		cout << "No";
	}
	else {
		cout << A << " " << B1 << " " << C;
	}
	return 0;
}

//������������M��N����M��N���Ʊ�ʾ��ʽ��M����0��N���ڵ���2С�ڵ���16��
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s = "", table = "0123456789ABCDEF";
	int M = 0, N = 0;
	cin >> M >> N;

	if (M == 0)
	{
		s = "0";
	}

	while (M)
	{
		if (M < 0)
		{
			M = -M;
			cout << "-";
		}
		s = table[M % N] + s;
		M /= N;
	}
	cout << s << endl;
	return 0;
}


#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//˼·��N��������ÿ������λ��ֵ�ֱ�Ϊ��X0*N^0 + X1*N^1 + X2*N^2 + ...
//X0��X1��X2���ǽ���λ��ֵ�����ǽ���ȡģ���������ǵ�ǰ�ͽ��Ƶ�λ��ֵΪ����
//Ȼ�������������������һ������λ�ļ���
int main()
{
	string ret;
	string table = "0123456789ABCDEF";    //����ת����
	int m, n;
	while (cin >> m >> n){
		bool flag = false;
		//����Ǹ�����תΪ���������һ��
		if (m < 0){
			m = 0 - m;
			flag = true;
		}
		//�����ƻ����Ӧ���ַ�����ӵ�ret
		while (m){
			ret += table[m%n];
			m /= n;
		}

		if (flag){
			ret += '-';
		}
		reverse(ret.begin(), ret.end());
		cout << ret << endl;
	}
	return 0;
}