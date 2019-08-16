#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int> arr, int left, int right, int val)
{
	if ((arr.size() == 0) || left > right) {
		return -1;
	}
	int mid = left + (right - left) / 2;
	if (arr[mid] == val) {
		return mid;
	}
	else if (arr[mid] < val) {
		left = mid + 1;
		return BinarySearch(arr, left, right, val);
	}
	else {
		right = mid - 1;
		return BinarySearch(arr, left, right, val);
	}
}

int main()
{
	int n;
	int val;
	vector<int> arr;
	while (cin >> n) {
		arr.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		cin >> val;
		cout << BinarySearch(arr, 0, n - 1, val) << endl;
	}
	system("pause");
	return 0;
}