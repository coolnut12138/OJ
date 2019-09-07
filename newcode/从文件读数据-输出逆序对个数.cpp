//#include <iostream>
//#include <string>
//#include <vector>
//#include <unordered_set>
//#include <algorithm>
//#include <fstream>
//using namespace std;
//
//int main()
//{
//	ifstream in("./word.txt");
//	string str;
//	unordered_set<string> st;
//	while (getline(in, str)) {
//		st.insert(str);
//	}
//	int count = 0;
//	for (auto e = st.begin(); e != st.end();) {
//		string tmp = *e;
//		reverse(tmp.begin(), tmp.end());
//		st.erase(e++);
//		if (st.find(tmp) != st.end()) {
//			count++;
//		}
//	}
//	cout << count << endl;
//	system("pause");
//	return 0;
//}


#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
	ifstream in("./word.txt");
	string str;
	unordered_map<string, int> mp;
	while (getline(in, str)) {
		++mp[str];
	}
	int count = 0;
	for (auto & e : mp)
	{
		str = e.first;
		reverse(str.begin(), str.end());
		if (mp[str] > 0)
		{
			if (str == e.first)
			{
				continue;
			}
			--mp[str];
			--mp[e.first];
			++count;
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}