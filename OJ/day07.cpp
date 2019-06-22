Fibonacci��������������ģ�
F[0] = 0
F[1] = 1
for each i �� 2: F[i] = F[i - 1] + F[i - 2]
��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...����Fibonacci�����е������ǳ�ΪFibonacci��������һ��N�����������Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX - 1����X + 1�����ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci����
�������� :
����Ϊһ��������N(1 �� N �� 1, 000, 000)
������� :
	 ���һ����С�Ĳ�����ΪFibonacci��"

//�ⷨһ�����n��쳲��������У��������ҵ���Ӧ��λ�ò�������С����
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

//�ⷨ��
#include <iostream>
using namespace std;

int main()
{
	int N;
	int left, right;
	int f, f0 = 0, f1 = 1;
	while (cin >> N){
		while (1){
			//����쳲���������
			f = f0 + f1;
			f0 = f1;
			f1 = f;
			//�ҵ����������ߵ������Ƚ�����֮����
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


��Ŀ����
����һ���ַ����������һ���㷨���ж����Ƿ�Ϊһ���Ϸ������Ŵ���

����һ���ַ���A�����ĳ���n���뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ���

����������
"(()())", 6
���أ�true
����������
"()a()()", 7
���أ�false

//no.1
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		stack<char> st;
		for (auto e : A){
			//ջ��Ӧ�ã�����������ţ���ѹջ
			if (e == '('){
				st.push(e);
			}
			else if (e == ')'){
				//����������ţ�����ջ��Ϊ�գ���ջ���������ţ����ͽ�һ�������ų�ջ
				if (!st.empty()){
					st.pop();
				}
				else{
					//������������ŵ���ջΪ����ƥ�䡣
					return false;
				}
			}
			else{
				//�б���ַ�Ҳ��ƥ��
				return false;
			}
		}
		if (st.empty()){
			//�����ַ��������꣬ջΪ�գ�����ȫƥ��
			return true;
		}
		//ջ��Ϊ�գ���ƥ��
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