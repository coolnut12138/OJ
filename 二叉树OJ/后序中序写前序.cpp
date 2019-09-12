//中序后序写前序
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<char> res;
void preOrder(const char* in, const char* post, int len) {
	if (len < 1) {
		return;
	}
	int i = 0;
	while (in[i] != post[len - 1]) {
		i++;
	}
	res.push_back(post[len - 1]);
	preOrder(in, post, i);
	preOrder(in + i + 1, post + i, len - i - 1);
}

int main()
{
	string InOrder;
	string PostOrder;
	while (cin >> InOrder >> PostOrder) {
		res.clear();
		const char *in = InOrder.c_str();
		const char *post = PostOrder.c_str();
		preOrder(in, post, InOrder.size());
		for (auto& e : res) {
			cout << e;
		}
		cout << endl;
	}
	return 0;
}