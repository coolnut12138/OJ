
//�������ֶ��������������������1�ĸ���
#include <iostream>
using namespace std;

int Count(int num)
{
	int count = 0;
	int max = 0;
	while (num){
		//�����������ж����һλ�Ƿ�Ϊ1
		if ((num & 1) == 1){
			count++;
		}
		else {
			//�������1����1�������Ѿ��Ͽ����жϸ����Ƿ����
			if (count > max){
				max = count;
			}
			count = 0;
		}
		num >>= 1;
	}
	if (count > max){
		max = count;
	}
	return max;
}

int main()
{
	int num;
	while (cin >> num){
		cout << Count(num) << endl;
	}
	return 0;
}


class LCA {
public:
	int getLCA(int a, int b) {
		// ����������·���ҳ���
		vector<int> patha;
		vector<int> pathb;
		patha.push_back(a);
		pathb.push_back(b);
		while (a >= 1){
			patha.push_back(a / 2);
			a /= 2;
		}
		while (b >= 1){
			pathb.push_back(b / 2);
			b /= 2;
		}
		int i = patha.size() - 1;
		int j = pathb.size() - 1;
		//Ȼ����бȽϣ�����������֤�����ҵ���
		while (i >= 0 && j >= 0){
			if (patha[i] == pathb[j]){
				i--;
				j--;
			}
			else{
				return patha[++i];
			}
		}
		return 1;
	}
};

