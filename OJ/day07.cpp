Fibonacci数列是这样定义的：
F[0] = 0
F[1] = 1
for each i ≥ 2: F[i] = F[i - 1] + F[i - 2]
因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X - 1或者X + 1，现在给你一个数N求最少需要多少步可以变为Fibonacci数。
输入描述 :
输入为一个正整数N(1 ≤ N ≤ 1, 000, 000)
输出描述 :
	 输出一个最小的步数变为Fibonacci数"

//解法一：求出n个斐波那契数列，在其中找到相应的位置并计算最小步长
#include <iostream>
#include <vector>
using namespace std;
int Fib(int n)
{
	if (0 == n){
		return 0;
	} 
	if(1 == n){
		return 1;
	} 
	return Fib(n - 1) + Fib(n - 2);
} 
int main()
{
	vector<int> v;
	int n;
	int count1 = 0;
	int count2 = 0;
	v.resize(32);
	for (int i = 0; i < 32; i++){
		v[i] = Fib(i);
	} 
	cin >> n;
	int lit, big;
	for (int i = 0; i < 31; i++){
		if (n == v[i]){
			cout << "0" << endl;
			return 0; 
		}
		if (n > v[i] && n < v[i + 1]){
			lit = v[i];
			big = v[i + 1];
		}
	} 
	while(lit != n){
			++count1;
			++lit;
		} 
	while(big != n){
				++count2;
				--big;
			} 
	cout << ((count1 < count2) ? count1 : count2) << endl;
	return 0;
}

//解法二
#include <iostream>
using namespace std;

int main()
{
	int N;
	int left, right;
	int f, f0 = 0, f1 = 1;
	while (cin >> N){
		while (1){
			//计算斐波那契数列
			f = f0 + f1;
			f0 = f1;
			f1 = f;
			//找到它左右两边的数，比较两者之差并输出
			if (f < N){
				left = N - f;
			}
			else {
				right = f - N;
				break;
			}
		}
		cout << min(left, right) << endl;
	}
	return 0;
}


题目描述
对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。

给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。

测试样例：
"(()())", 6
返回：true
测试样例：
"()a()()", 7
返回：false

//no.1
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		stack<char> st;
		for (auto e : A){
			//栈的应用，如果是左括号，就压栈
			if (e == '('){
				st.push(e);
			}
			else if (e == ')'){
				//如果是右括号，并且栈不为空（即栈中有左括号），就将一个左括号出栈
				if (!st.empty()){
					st.pop();
				}
				else{
					//如果还有右括号但是栈为空则不匹配。
					return false;
				}
			}
			else{
				//有别的字符也不匹配
				return false;
			}
		}
		if (st.empty()){
			//整个字符串遍历完，栈为空，则完全匹配
			return true;
		}
		//栈不为空，则不匹配
		return false;
	}
};


//no.2
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		stack<char> st;
		for (auto e : A){
			switch (e){
			case '(':
				st.push(e);
				break;
			case ')':
				if (st.empty() || st.top() != '('){
					return false;
				}
				else{
					st.pop();
				}
				break;
			}
		}
		if (st.empty()){
			return true;
		}
		return false;
	}
};