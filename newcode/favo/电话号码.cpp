#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int t;
	while (cin >> t) {
		vector<pair<int, pair<string, string>>> strMp;
		strMp.resize(t);
		for (int i = 0; i < t; i++) {
			cin >> strMp[i].first;
			cin >> strMp[i].second.first;
		}
		for (int i = 0; i < t; i++) {
			if (strMp[i].first < 11) {
				strMp[i].second.second = "NO";
			}
			else if (strMp[i].first == 11 && strMp[i].second.first[0] == '8') {
				strMp[i].second.second = "YES";
			}
			else if (strMp[i].first == 11 && strMp[i].second.first[0] != '8') {
				strMp[i].second.second = "NO";
			}
			else if (strMp[i].first > 11) {
				string tmp;    //记录第一个8后面的字符串长度
				int pos = strMp[i].second.first.find('8');
				if (pos < 0) {
					strMp[i].second.second = "NO";
				}
				else {
					if (strMp[i].second.first.size() - pos >= 11) {
						strMp[i].second.second = "YES";
					}
					else {
						strMp[i].second.second = "NO";
					}
				}
			}
		}

		for (const auto& e : strMp) {
			cout << e.second.second << endl;
		}
	}
	return 0;
}