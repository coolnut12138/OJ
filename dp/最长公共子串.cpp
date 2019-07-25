链接：https://www.nowcoder.com/questionTerminal/9ae56e5bdf4f480387df781671db5172
来源：牛客网

我们有两个字符串m和n，如果它们的子串a和b内容相同，则称a和b是m和n的公共子序列。
子串中的字符不一定在原字符串中连续。
例如字符串“abcfbc”和“abfcab”，其中“abc”同时出现在两个字符串中，
因此“abc”是它们的公共子序列。此外，“ab”、“af”等都是它们的字串。
现在给你两个任意字符串（不包含空格），请帮忙计算它们的最长公共子序列的长度。

// write your code here cpp
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
int dp[1025][1025];
int LCS(string s1, int len1, string s2, int len2)
{
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
    }
    return dp[len1][len2];
}

int main()
{
    string s1, s2;
    while(cin >> s1 >> s2){
        int size1 = s1.size();
        int size2 = s2.size();
        cout << LCS(s1, size1, s2, size2) << endl;
    }
    return 0;
}