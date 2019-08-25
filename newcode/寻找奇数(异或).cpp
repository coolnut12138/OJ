题目描述
现在有一个长度为n的正整数序列，其中只有【一种】数值出现了奇数次，其他数值均出现偶数次，请你找出那个出现奇数次的数值。
输入描述:
第一行：一个整数n，表示序列的长度。第二行：n个正整数ai，两个数中间以空格隔开。
输出描述:
一个数，即在序列中唯一出现奇数次的数值。
示例1
输入
5
2 1 2 3 1
输出
3
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    vector<int> arr;
    int n;
    while(cin >> n){
        int ret = 0;
        arr.resize(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            ret ^= arr[i];
        }
        cout << ret << endl;
    }
    return 0;
}
