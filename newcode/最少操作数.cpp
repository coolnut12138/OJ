#include <iostream>
#include <string>
#include <vector>
using namespace std;

int ChangeWord(string word1, string word2){
    if(word1.empty() || word2.empty()){
        return max(word1.size(), word2.size());
    }
    int size1 = word1.size();
    int size2 = word2.size();
    vector<vector<int>> dp(1 + size1, vector<int>(1 + size2, 0));
    for(int i = 0; i <= size1; i++){
        dp[i][0] = i;
    }
    for(int i = 0; i <= size2; i++){
        dp[0][i] = i;
    }
    
    for(int i = 1; i <= size1; i++){
        for(int j = 1; j <= size2; j++){
            if(word1[i - 1] == word2[j - 1]){
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j]);
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
            else{
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j]);
                dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j - 1]);
            }
        }
    }
    return dp[size1][size2];
}

int main()
{
    string s1, s2;
    while(cin >> s1 >> s2){
        cout << ChangeWord(s1, s2) << endl;
    }
}