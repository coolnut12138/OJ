https://www.nowcoder.com/practice/23462ed010024fcabb7dbd3df57c715e?tpId=46&tqId=29115&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
题目描述

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right 
which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.

给定一个m*n的网格，网格用非负数填充，找到一条从左上角到右下角的最短路径。
注：每次只能向下或者向右移动。
//方法：动态规划
//子状态：从(0,0)到(1,0)(1,1)(2,1)...(i,j)的最小路径和
		F(i,j):从(0,0)到F(i,j)的最小路径和
//递推公式：
		F(i,j) = min(F(i-1, j), F(i, j-1)) + grid(i,j);
//初始值：
	F(0,0) = grid(0,0);
	第0行：F(0,i) = F(0,i-1) + grid(0, i);
	第0列：F(i,0) = F(i-1,0) + grid(i, 0);
//返回值：
	F(m-1,n-1)
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.empty()){
            return 0;
        }
        
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> dp(row, vector<int>(col, 0));
        dp[0][0] = grid[0][0];
        //初始化行
        for(int i = 1; i < row; i++){
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }
        //初始化列
        for(int i = 1; i < col; i++){
            dp[0][i] = grid[0][i] + dp[0][i-1];
        }
        
        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[row-1][col-1];
    }
};