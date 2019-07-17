[编程题]查找兄弟单词
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isBrother(string s1, string s2)
{
	if (s1.size() == s2.size()){
		if (s1 == s2){
			return false;
		}

		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		if (s1 == s2){
			return true;
		}
	}
	return false;
}

int main()
{
	int n;
	while (cin >> n){
		string words;
		vector<string> v;
		for (int i = 0; i < n; i++){
			cin >> words;
			v.push_back(words);
		}
		sort(v.begin(), v.end());
		string word;
		string tmp = "";
		int pos = 0;
		cin >> word >> pos;
		int count = 0;    //计数兄弟单词的个数
		for (auto e : v){
			if (isBrother(word, e)){
				count++;
				if (count == pos){
					tmp = e;
				}
			}
		}
		if (!v.empty()){
			cout << count << endl;
		}
		if (count >= pos){
			cout << tmp << endl;
		}
	}
	return 0;
}