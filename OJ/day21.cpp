MP3���λ����������:
https ://www.nowcoder.com/questionTerminal/eaf5b886bd6645dd9cfb5406f3753e15
����˵����
1 �����������
2 �������� U����D

������� :
���˵��
1 �����ǰ�б�
2 �����ǰѡ�и���

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int num;    //��������
	string order;    //����

	while (cin >> num >> order){
		int index = 1;    //��ǰ�������
		int first = 1;    //��ǰҳ���һ�׸������
		if (num <= 4){
			//����Ҫ��ҳ
			//��������
			for (int i = 0; i < order.size(); i++){
				if (index == 1 && order[i] == 'U'){
					index = num;
				}
				else if (index == num && order[i] == 'D'){
					index = 1;
				}
				else if (order[i] == 'U'){
					index--;
				}
				else{
					index++;
				}
			}
			for (int i = 1; i <= num - 1; i++){
				cout << i << " ";
			}
			cout << num << endl;
			cout << index << endl;
		}
		else{
			//������������4��,��Ҫ��ҳ
			//��������
			for (int i = 0; i < order.size(); i++){
				if (first == 1 && index == 1 && order[i] == 'U'){    //��Ҫ���Ϸ�ҳ
					first = num - 3;
					index = num;
				}
				else if (first == num - 3 && index == num && order[i] == 'D'){    //��Ҫ���·�ҳ
					first = 1;
					index = 1;
				}
				else if (first != 1 && index == first && order[i] == 'U'){    //������һ��
					first--;
					index--;
				}
				else if (first != num - 3 && index == first + 3 && order[i] == 'D'){    //������һ��
					first++;
					index++;
				}
				else if (order[i] == 'U'){
					index--;
				}
				else if (order[i] == 'D'){
					index++;
				}
			}
			for (int i = first; i < first + 3; i++){
				cout << i << " ";
			}
			cout << (first + 3) << endl;
			cout << index << endl;
		}
	}
	return 0;
}


https://www.nowcoder.com/questionTerminal/5a0a2c7e431e4fbbbb1ff32ac6e8dfa0
ϴ��

#include <iostream>
#include <vector>
using namespace std;

//����
void split(int n, vector<int>& cards, vector<int>& left, vector<int>& right)
{
	left.assign(cards.begin(), cards.begin() + n);
	right.assign(cards.begin() + n, cards.end());
}

//ϴ��
vector<int> Wash(int n, vector<int>& cards)
{
	vector<int> left, right;
	split(n, cards, left, right);
	vector<int> ret;
	for (int i = 0; i < n; i++){
		ret.push_back(left[i]);
		ret.push_back(right[i]);
	}
	return ret;
}

int main()
{
	int T, n, k;
	vector<int> ret;
	while (cin >> T){
		while (T--){
			vector<int> cards;
			cin >> n >> k;
			cards.resize(2 * n);
			for (size_t i = 0; i < cards.size(); i++){
				cin >> cards[i];
			}
			//��ԭ�ƴ�����
			ret = cards;
			for (int i = 0; i < k; i++){
				//ϴһ���ƣ��Ƶ�˳����
				ret = Wash(n, ret);
			}
			int num = ret.size();
			for (int i = 0; i < num - 1; i++){
				cout << ret[i] << " ";
			}
			//ÿһ������Ϊһ��
			cout << ret[num - 1] << endl;
		}
	}
	return 0;
}