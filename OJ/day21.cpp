MP3光标位置输入描述:
https ://www.nowcoder.com/questionTerminal/eaf5b886bd6645dd9cfb5406f3753e15
输入说明：
1 输入歌曲数量
2 输入命令 U或者D

输出描述 :
输出说明
1 输出当前列表
2 输出当前选中歌曲

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int num;    //歌曲总数
	string order;    //命令

	while (cin >> num >> order){
		int index = 1;    //当前歌曲编号
		int first = 1;    //当前页面第一首歌曲编号
		if (num <= 4){
			//不需要翻页
			//解析命令
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
			//音乐数量超过4首,需要翻页
			//解析命令
			for (int i = 0; i < order.size(); i++){
				if (first == 1 && index == 1 && order[i] == 'U'){    //需要向上翻页
					first = num - 3;
					index = num;
				}
				else if (first == num - 3 && index == num && order[i] == 'D'){    //需要向下翻页
					first = 1;
					index = 1;
				}
				else if (first != 1 && index == first && order[i] == 'U'){    //向上走一格
					first--;
					index--;
				}
				else if (first != num - 3 && index == first + 3 && order[i] == 'D'){    //向下走一格
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
洗牌

#include <iostream>
#include <vector>
using namespace std;

//分牌
void split(int n, vector<int>& cards, vector<int>& left, vector<int>& right)
{
	left.assign(cards.begin(), cards.begin() + n);
	right.assign(cards.begin() + n, cards.end());
}

//洗牌
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
			//将原牌存起来
			ret = cards;
			for (int i = 0; i < k; i++){
				//洗一次牌，牌的顺序会变
				ret = Wash(n, ret);
			}
			int num = ret.size();
			for (int i = 0; i < num - 1; i++){
				cout << ret[i] << " ";
			}
			//每一组数据为一行
			cout << ret[num - 1] << endl;
		}
	}
	return 0;
}