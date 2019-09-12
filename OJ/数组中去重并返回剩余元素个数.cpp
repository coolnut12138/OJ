//将数组中重复的数去重并计算数组中剩余元素的个数
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	set<string> st;
	string input;
	while (cin >> input) {
		st.clear();
		if (input.size() <= 0) {
			cout << 0 << endl;
			continue;
		}
		string num = "";
		int j = 0;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == ',') {
				num = input.substr(j, i - j);
				j = i + 1;
				st.insert(num);
			}
		}
		st.insert(input.substr(j, input.size() - j));
		cout << st.size() << endl;
	}
	return 0;
}
