链接：https://www.nowcoder.com/questionTerminal/eac8c671a0c345b38aa0c07aba40097b?orderByHotValue=0&page=1&onlyReference=false
来源：牛客网

输入描述 :
每个测试输入包含 n个空格分割的n个整数，n不超过100，其中有一个整数出现次数大于等于n / 2。


输出描述 :
输出出现次数大于等于n / 2的数。
示例1
输入
3 9 3 2 5 6 7 3 2 3 3 3
输出
3
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	int n;
	int arr[10240] = { 0 };
	int len = 0;
	while (cin >> n){
		v.push_back(n);
		/*if (cin.get() == '\n'){
		break;
		}*/
	}
	len = v.size() / 2;
	auto begin = v.begin();
	while (begin != v.end()){
		arr[*begin]++;
		begin++;
	}
	for (int i = 0; i < 10240; i++){
		if (arr[i] >= len){
			cout << i << endl;
		}
	}
	system("pause");
	return 0;
}

//解法二：排序，但是sort的时间复杂度为O(n*logn)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<int> v;
	while (cin >> n){
		v.push_back(n);
	}
	//排序
	sort(v.begin(), v.end());
	//在中间的数就是出现次数超过一半的数
	cout << v[v.size() / 2 - 1] << endl;
	return 0;
}

//解法三：最优解
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	int n;
	while (cin >> n){
		v.push_back(n);
	}

	int count = 0;    //标记元素出现的次数
	int tmp = v[0];    //记录当前元素
	//思路：当元素出现一次，count计数+1，当遇到别的元素count-1，
	//当count减为0时，更新tmp为当前元素，并且count重新计数
	//遍历完数组，如果count还不为0，那么tmp就是出现次数大于一半的数
	for (int i = 0; i < v.size(); i++){
		if (v[i] == tmp){
			count++;
		}
		else {
			count--;
		}

		if (count == 0){
			tmp = v[i];
			count++;
		}
	}
	cout << tmp << endl;
	return 0;
}



题目描述
读入一个字符串str，输出字符串str中的连续最长的数字串
输入描述 :
个测试输入包含1个测试用例，一个字符串str，长度不超过255。
输出描述 :
在一行内输出str中里连续最长的数字串。
示例1
输入
abcd12345ed125ss123456789
输出
123456789
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str, res, cur;
	getline(cin, str);
	for (size_t i = 0; i <= str.size(); i++){
		if (str[i] >= '0' && str[i] <= '9'){
			cur += str[i];
		}
		else{
			if (res.size() < cur.size()){
				res = cur;
			}
			else{
				cur.clear();
			}
		}
	}
	cout << res << endl;
	system("pause");
	return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str, ret, cur;
	while (getline(cin, str)){    //cin遇到空格就会结束，所以使用getline
		for (size_t i = 0; i <= str.size(); ++i){    //要遍历到最后一个元素，这样才不会遗漏最后一个字符串
			if (str[i] >= '0' && str[i] <= '9'){
				cur += str[i];
			}
			else {
				//保存最长子串
				if (ret.size() < cur.size()){
					ret = cur;
				}
				else{
					cur.clear();
				}
			}
		}
		cout << ret << endl;
	}
	return 0;
}
