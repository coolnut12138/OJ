链接：http://pre.nowcoder.com/questionTerminal/9d1559511b3849deaa71b576fa7009dc?orderByHotValue=0&commentTags=Java
来源：牛客网

“回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。花花非常喜欢这种拥有对称美的回文串，生日的时候她得到两个礼物分别是字符串A和字符串B。现在她非常好奇有没有办法将字符串B插入字符串A使产生的字符串是一个回文串。你接受花花的请求，帮助她寻找有多少种插入办法可以使新串是一个回文串。如果字符串B插入的位置不同就考虑为不一样的办法。
例如：
A = “aba”，B = “b”。这里有4种把B插入A的办法：
* 在A的第一个字母之前: "baba" 不是回文
* 在第一个字母‘a’之后 : "abba" 是回文
* 在字母‘b’之后 : "abba" 是回文
* 在第二个字母'a'之后 "abab" 不是回文
所以满足条件的答案为2

输入描述 :
每组输入数据共两行。
第一行为字符串A
第二行为字符串B
字符串长度均小于100且只包含小写字母


输出描述 :
输出一个数字，表示把字符串B插入字符串A之后构成一个回文串的方法数
示例1
输入
aba
b
输出
2
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


链接：https://www.nowcoder.com/questionTerminal/5a304c109a544aef9b583dce23f5f5db?toCommentId=1474080
来源：牛客网

输入描述 :
输入为两行。 第一行一个整数n(1 <= n <= 100000)，表示一共有n个元素 第二行为n个数，即每个元素, 每个整数都在32位int范围内。以空格分隔。


输出描述 :
所有连续子数组中和最大的值。
示例1
输入
3 - 1 2 1
输出
3
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