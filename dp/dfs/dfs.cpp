#include <iostream>
#include <vector>
using namespace std;

void Dfs(int index, int n, vector<int>& boxs, vector<int>& books) {
	if (index == n + 1) {
		for (int i = 1; i <= n; i++) {
			cout << boxs[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (books[i] == 0) {
			boxs[index] = i;
			books[i] = 1;
			Dfs(index + 1, n, boxs, books);
			books[i] = 0;
		}
	}
}

int main()
{
	int n;
	vector<int> boxs;
	vector<int> books;

	cin >> n;
	boxs.resize(n + 1, 0);
	books.resize(n + 1, 0);
	Dfs(1, n, boxs, books);
	system("pause");
	return 0;
}