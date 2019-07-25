链接：https://www.nowcoder.com/questionTerminal/d83721575bd4418eae76c916483493de?source=relative
来源：牛客网

广场上站着一支队伍，她们是来自全国各地的扭秧歌代表队，现在有她们的身高数据，请你帮忙找出身高依次递增的子序列。 例如队伍的身高数据是（1、7、3、5、9、4、8），其中依次递增的子序列有（1、7），（1、3、5、9），（1、3、4、8）等，其中最长的长度为4。

输入描述:
输入包含多组数据，每组数据第一行包含一个正整数n（1≤n≤1000）。

紧接着第二行包含n个正整数m（1≤n≤10000），代表队伍中每位队员的身高。

// write your code here cpp
//借助辅助数组完成每一部分的人数计算
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector<int> peo;
    while(cin >> n){
        peo.resize(n);
        for(int i = 0; i < n; i++){
            cin >> peo[i];
        }
        
        vector<int> tmp(n, 1);
        int count = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(peo[i] > peo[j]){
                    tmp[i] = max(tmp[i], tmp[j] + 1);
                }
            }
            count = max(tmp[i], count);
        }
        cout << count << endl;
    }
    return 0;
}