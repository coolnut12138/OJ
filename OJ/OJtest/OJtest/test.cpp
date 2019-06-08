#define _CRT_SECURE_NO_WARNINGS 1
#if 0
//回文串是一个正读反读都一样的字符串，花花喜欢
#include <iostream>
#include <string>
using namespace std;

bool ishuiwen(string& s)
{
	int begin = 0;
	int end = s.size() - 1;
	while (begin < end)    //这里用迭代器不太合适，因为当字符个数为偶数时，begin和end会刚好擦肩而过
	{
		if (s[begin] != s[end]){
			return false;
		}
		++begin;
		--end;
	}
	return true;
}

int main()
{
	string str1;
	string str2;
	string res;
	int count = 0;
	cin >> str1;
	cin >> str2;
	int len = str1.size();
	for (int i = 0; i <= len; i++)    //注意边界条件，最后一个位置也要插入
	{
		res = str1;
		res.insert(i, str2);
		if (ishuiwen(res)){
			count++;
		}
	}
	cout << count << endl;
	return 0;
}
#endif

#if 0
//一个数组有N个元素，求连续子数组的最大和，例如[-1 2 1],结果为3。
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<int> v;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	auto vit = v.begin();
	long long sum = v[0];
	long long max = v[0];
	while (vit != v.end())
	{
		//局部总和 和 全部总和
		//局部总和max：如果加下一个值的和大于前一个值，那么直接更新局部总和的值。
		//全部总和sum：如果局部总和大于全部总和，直接更新全部总和的值为局部总和
		max = (max + *vit) > *vit ? (max + *vit) : *vit;
		sum = max > sum ? max : sum;
		++vit;
	}
	cout << sum << endl;
	system("pause");
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	int n;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	int tmp = v[0] + v[1] - 1;
	int max = v[0] + v[1] - 1;
	for (int i = 1; i < n; i++){
		for (int j = i + 1; j < n; j++){
			tmp = (v[i] + v[j] - abs(i - j)) > tmp ? (v[i] + v[j] - abs(i - j)) : tmp;
			max = tmp > max ? tmp : max;
		}
	}
	cout << max << endl;
	system("pause");
	return 0;
}
#endif

#if 0
//将字符串转数字，如果遇到不是数字的则直接返回0
#include <iostream>
#include <string>
using namespace std;
int StrToInt(string str) {
	auto sit = str.begin();
	long long num = 0;
	int flag = 1;
	//判断符号
	if (*sit == '+'){
		++sit;
	}
	else if (*sit == '-'){
		flag = -1;
		++sit;
	}
	//逐个转换
	while (sit != str.end()){
		if (*sit >= '0' && *sit <= '9'){
			num = num * 10 + (*sit - '0');
			++sit;
		}
		else{
			num = 0;
			break;
		}
	}
	return num * flag;
}
int main()
{
	string s = "1111";
	cout << StrToInt(s) << endl;
	system("pause");
	return 0;
}


//链接：https://www.nowcoder.com/questionTerminal/1183548cd48446b38da501e58d5944eb
//来源：牛客网
//
//二货小易有一个W*H的网格盒子，网格的行编号为0~H - 1，网格的列编号为0~W - 1。每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。
//对于两个格子坐标(x1, y1), (x2, y2)的欧几里得距离为:
//((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) 的算术平方根
//小易想知道最多可以放多少块蛋糕在网格盒子里。
//
//输入描述 :
//每组数组包含网格长宽W, H，用空格分割.(1 ≤ W、H ≤ 1000)
//
//
//输出描述 :
//	 输出一个最多可以放的蛋糕数
//	 示例1
//	 输入
//	 3 2
//	 输出
//	 4
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int W, H;
	cin >> W >> H;
	int ret = 0;
	if (0 == W % 4 || 0 == H % 4){
		ret = W * H / 2;
	}
	else if (0 == W % 2 && 0 == H % 2){
		ret = W * H / 2 + 2;
	}
	else{
		ret = W * H / 2 + 1;
	}
	cout << ret << endl;
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	vector<int>array;
	array.push_back(100);
	array.push_back(300);
	array.push_back(300);
	array.push_back(300);
	array.push_back(300);
	array.push_back(500);
	vector<int>::iterator itor;
	for (itor = array.begin(); itor != array.end(); itor++)
	{
		if (*itor == 300)
		{
			itor = array.erase(itor);
		}
	}

	for (itor = array.begin(); itor != array.end(); itor++)
	{
		cout << *itor << "" << endl;
	}
	system("pause");
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

class parent
{
	int i;
protected:
	int x;
public:
	parent()
	{
		x = 0;
		i = 0;
	}
	void change()
	{
		x++;
		i++;
	}
	void display();
};
class son :public parent
{
public:
	void modify();
};
void parent::display() { cout << "x=" << x << endl; }
void son::modify(){ x++; }

int main()
{
	son A;
	parent B;
	A.display();
	A.change();
	A.modify();
	A.display();
	B.change();
	B.display();
	system("pause");
	return 0;
}
#endif

#if 0
//求最小步长变成一个斐波那契数
#include <iostream>
#include <vector>
using namespace std;
int Fib(int n)
{
	if (0 == n){
		return 0;
	}
	if (1 == n){
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
			system("pause");
			return 0;
		}
		if (n > v[i] && n < v[i + 1]){
			lit = v[i];
			big = v[i + 1];
		}
	}
	while (lit != n){
		++count1;
		++lit;
	}
	while (big != n){
		++count2;
		--big;
	}
	cout << ((count1 < count2) ? count1 : count2) << endl;
	system("pause");
	return 0;
}

//括号匹配
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		stack<char> st;
		for (auto e : A){
			if (e == '('){
				st.push(e);
			}
			else if (e == ')'){
				if (!st.empty()){
					st.pop();
				}
				else{
					return false;
				}
			}
			else {
				return false;
			}
		}

		if (st.empty())
		{
			return true;
		}
		return false;
	}
};
#endif

#if 0
#include <iostream>
using namespace std;
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};

RandomListNode* BuyNode(int label)
{
	RandomListNode* node = new struct RandomListNode(label);
	node->next = nullptr;
	node->random = nullptr;
	return node;
}

RandomListNode* Clone(RandomListNode* pHead)
{
	//1、复制原链表，让新结点跟在老结点后面
	RandomListNode* oldNode = pHead;
	while (oldNode != nullptr){
		RandomListNode* newNode = BuyNode(oldNode->label);
		newNode->next = oldNode->next;
		oldNode->next = newNode;

		oldNode = oldNode->next->next;
	}

	//2、处理random指针
	oldNode = pHead;
	while (oldNode != nullptr){
		RandomListNode* newNode = oldNode->next;
		if (oldNode->random != nullptr){
			newNode->random = oldNode->random->next;
		}
		oldNode = oldNode->next->next;
	}

	//3、拆分链表
	oldNode = pHead;
	RandomListNode* newHead = pHead->next;
	while (oldNode != nullptr){
		RandomListNode* newNode = oldNode->next;
		oldNode->next = newNode->next;
		if (oldNode->next != nullptr){
			newNode->next = oldNode->next->next;
		}
		oldNode = oldNode->next;
	}
	return newHead;
}

int main()
{
	struct RandomListNode *n1 = BuyNode(1);
	struct RandomListNode *n2 = BuyNode(2);
	struct RandomListNode *n3 = BuyNode(3);
	struct RandomListNode *n4 = BuyNode(4);

	n1->next = n2;
	n1->random = n3;
	n2->next = n3;
	n2->random = n1;
	n3->next = n4;
	n3->random = n3;
	Clone(n1);

	int a = 10;
	int b = 3;
	//int *const p = &a;
	int const*p = &a;
	cout << *p << endl;
	p = &b;
	//*p = b;
	cout << *p << endl;
	system("pause");
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;

int getcount(int n, int m)
{
	if (m == 0 || n == 0){
		//return 0;
		return 1;
	}
	/*if (m == 1 && n >= 1){
	return n + 1;
	}
	if (n == 1 && m >= 1){
	return m + 1;
	}
	if (n > 1 && m > 1){*/
	return getcount(n - 1, m) + getcount(n, m - 1);
	/*}
	else {
	return -1;
	}*/
}

int main()
{
	int n, m;
	cin >> n >> m;
	cout << getcount(n, m) << endl;
	system("pause");
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

bool isPrime(int num)
{
	//判断是否是素数
	for (int i = 2; i < num; i++){
		if (0 == num % i){
			return false;
		}
	}
	return true;
}

int main()
{
	int num, i, j, res1, res2;
	int sub, litsub;
	while (cin >> num){
		sub = litsub = num;
		for (i = 2; i < num - 2; i++){
			j = num - i;
			if (isPrime(i) && isPrime(j)){
				sub = abs(i - j);
			}
			if (sub < litsub){
				litsub = sub;
				res1 = i;
				res2 = j;
			}
		}
		cout << res1 << endl;
		cout << res2 << endl;
	}
	system("pause");
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
class Base
{
public:
	Base(int j) : i(j) {}
	virtual ~Base(){}
	void func1() {
		i *= 10;
		func2();
	}
	int getValue(){
		return i;
	}
	virtual void func2() {
		i++;
	}
protected:
	int i;
};
class Child : public Base {
public:
	Child(int j) :Base(j) {}
	void func1() {
		i *= 100;
		func2();
	}
protected:
	void func2() {
		i += 2;
	}
};
int main()
{
	Base *pb = new Child(1);
	pb->func1();
	cout << pb->getValue() << endl;
	delete pb;
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
int main()
{
	try{ void *p = new char[0x3fffffff]; }
	catch (exception e){
		cout << e.what() << endl;
	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	int add = 0;
	int mul = 1;
	vector<int> v;
	while (cin >> n){
		for (int i = 0; i < n; i++){
			cin >> m;
			add += m;
			mul *= m;
			v.push_back(m);
		}
		sort(v.begin(), v.end());

		int count = 0;
		while (1){
			if (add > mul){
				++count;
				v.pop_back();
			}
			else {
				v.pop_back();
			}
			if (v.size() == 0){
				break;
			}
			add = 0;
			mul = 1;
			for (size_t i = 0; i < v.size(); i++){
				add += m;
				mul *= m;
			}
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}
#endif


#if 0
#include <iostream>
#include <vector>
using namespace std;

int findMinimum(int n, vector<int> left, vector<int> right) {
	// write code here
	int leftNum = 0;
	int rightNum = 0;
	int rightMax = 0;    //记录右手有哪个最多的手套个数
	int RcolorNum = 0;    //记录右手有几个颜色有手套
	int LcolorNum = 0;    //记录左手有几个颜色有手套
	//右手套可以取最大值加上有几个颜色有手套的值。比如4号颜色最多是6个，1号和2号都有手套，那么就取6 + 2 = 8个
	for (int i = 0; i < n; i++){
		if (left[i] != 0){
			++LcolorNum;
		}
		if (right[i] != 0){
			++RcolorNum;
		}
		rightMax = rightMax > right[i] ? rightMax : right[i];
	}
	if (LcolorNum == n || RcolorNum == n){
		return n + 1;
	}
	rightNum = rightMax + RcolorNum - 1;    //右边数量等于最大数 + 剩下的存在的颜色个数
	leftNum = n - (2 * n - (LcolorNum + RcolorNum));
	return rightNum + leftNum;
}

int main()
{
	vector<int> a;
	a.push_back(0);
	a.push_back(7);
	a.push_back(1);
	a.push_back(6);
	vector<int> b;
	b.push_back(1);
	b.push_back(5);
	b.push_back(0);
	b.push_back(6);

	cout << findMinimum(4, a, b) << endl;
	system("pause");
	return 0;
}
#endif


#if 0
#include <iostream>
using namespace std;

void MergeSort(int arr[], int len, int extra[])
{

}

int main()
{
	int extra[] = { 0 };
	int arr[10] = { 3, 1, 4, 5, 2, 6, 2, 9, 8, 5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr, len, extra);
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;

int main()
{
	const int a = 10;
	int *pa = (int*)&a;
	*pa = 20;
	cout << a << " " << *pa << endl;
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
using namespace std;

int count(int n)
{
	int sum = 0;
	int count = 0;
	for (int i = n; i >= 2; i--){
		sum = 0;
		for (int j = 1; j < i; j++){
			if (i % j == 0){
				sum += j;
			}
		}
		if (sum == i){
			count++;
		}
	}
	return count;
}

int main()
{
	int n;
	while (cin >> n){
		cout << count(n) << endl;
	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
using namespace std;


int main()
{
	string s;
	while (getline(cin, s)){
		int size = s.size();
		string left, right;
		int leftcount = 0;
		for (int i = 0; i < size; i++){
			leftcount++;
			if (s[i] != '-'){
				left += s[i];
			}
			else{
				break;
			}
		}
		for (int i = leftcount; i < size; i++){
			right += s[i];
		}
		int leftlen = left.size() / 2 + 1;
		int rightlen = right.size() / 2 + 1;
		if (left == "joker JOKER" || right == "joker JOKER"){
			cout << "joker JOKER" << endl;
		}
		if (leftlen == 4 && rightlen != 4){
			cout << left << endl;
		}
		else if (leftlen != 4 && rightlen == 4){
			cout << right << endl;
		}
		else if (leftlen == 4 && rightlen == 4){
			cout << ((left > right) ? left : right) << endl;
		}
		if (leftlen == 1 && rightlen == 1){
			cout << ((left > right) ? left : right) << endl;
		}
		else if (leftlen == 2 && rightlen == 2){
			cout << ((left > right) ? left : right) << endl;
		}
		else if (leftlen == 3 && rightlen == 3){
			cout << ((left > right) ? left : right) << endl;
		}
		else if (leftlen == 5 && rightlen == 5){
			cout << ((left > right) ? left : right) << endl;
		}
	}
	system("pause");
	return 0;
}
#endif


#if 0
#include <iostream>
#include <string>
using namespace std;

bool isBigger(string left, string right)
{
	//左边大返回真
	if (left[0] == '2' && right[0] != '2'){
		return true;
	}
	else if (left[0] != '2' && right[0] == '2'){
		return false;
	}
	else if (left[0] == 'A' && right[0] != 'A'){
		return true;
	}
	else if (left[0] != 'A' && right[0] == 'A'){
		return false;
	}
	return left > right;
}

int main()
{
	string s;
	while (getline(cin, s)){
		int size = s.size();
		string left, right;
		int leftcount = 0;
		for (int i = 0; i < size; i++){
			leftcount++;
			if (s[i] != '-'){
				left += s[i];
			}
			else{
				break;
			}
		}
		for (int i = leftcount; i < size; i++){
			right += s[i];
		}
		int leftlen = left.size() / 2 + 1;
		int rightlen = right.size() / 2 + 1;
		if (left == "joker JOKER" || right == "joker JOKER"){
			cout << "joker JOKER" << endl;
			continue;
		}
		if (leftlen == 4 && rightlen != 4){
			cout << left << endl;
		}
		else if (leftlen != 4 && rightlen == 4){
			cout << right << endl;
		}
		else if (leftlen == 4 && rightlen == 4){
			cout << ((left > right) ? left : right) << endl;
		}

		if (leftlen != rightlen){
			cout << "ERROR" << endl;
			continue;
		}
		//牌的数量
		if (leftlen == 1 && rightlen == 1){
			if (isBigger(left, right)){
				cout << left << endl;
			}
			else{
				cout << right << endl;
			}
		}
		else if (leftlen == 2 && rightlen == 2){
			if (left[0] != left[1] || right[0] != right[1]){
				cout << "ERROR" << endl;
				continue;
			}
			if (isBigger(left, right)){
				cout << left << endl;
			}
			else{
				cout << right << endl;
			}
		}
		else if (leftlen == 3 && rightlen == 3){
			if ((left[0] != left[1] && left[0] != left[2]) || (right[0] != right[1] && right[0] != right[2])){
				cout << "ERROR" << endl;
				continue;
			}
			if (isBigger(left, right)){
				cout << left << endl;
			}
			else{
				cout << right << endl;
			}
		}
		else if (leftlen == 5 && rightlen == 5){
			if (isBigger(left, right)){
				cout << left << endl;
			}
			else{
				cout << right << endl;
			}
		}
	}
	system("pause");
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

template <class T>
struct sum{
	static void foo(T op1, T op2){
		cout << op1 << op2;
	}
};


int main()
{
	/*int a[] = { 1, 2, 3, 4, 5 };
	int *p[] = { a, a + 1, a + 2, a + 3 };
	int **q = p;
	cout << *(p[0] + 1) + **(q + 2) << endl;*/
	sum<int>::foo(1, 3);
	long long a = 1, b = 2, c = 3;
	printf("%d %d %d", a, b, c);
	return 0;
}
#endif
