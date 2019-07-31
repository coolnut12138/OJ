https://www.nowcoder.com/practice/166eaff8439d4cd898e3ba933fbc6358?tpId=46&tqId=29117&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
题目描述：
在一个m*n的网格的左上角有一个机器人，机器人在任何时候只能向下或者向右移动，
机器人试图到达网格的右下角，有多少可能的路径。
//方法：动态规划
//子状态：
	从(0,0)到(1,0)(1,1)(2,1)...(m-1,n-1)的路径数
	F(i,j):从(0,0)到F(i,j)的路径数
//状态递推：
	F(i,j) = F(i-1, j) + F(i, j-1)
//初始值：
	第一行和第一列的初始值都是1
//返回值：
	F(m-1,n-1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m < 0 || n < 0){
            return 0;
        }
        
        //第0行和第0列初始化为1
        vector<vector<int>> dp(m, vector<int>(n, 1));
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};