https://www.nowcoder.com/practice/3cdf08dd4e974260921b712f0a5c8752?tpId=46&tqId=29116&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
题目描述

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as1and0respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is2.

Note: m and n will be at most 100.
机器人还是要从网格左上角到达右下角，
但是网格中添加了障碍物，障碍物用1表示
//方法：动态规划
//子状态：从(0,0)到(1,0)(1,1)(2,1)...(i,j)的路径总数
		F(i,j):从(0,0)到(i,j)的路径总数
//递推公式：
	F(i,j):如果obstacleGrid[i][j] == 1,则dp[i][j] = 0;	//走不通
		   否则dp[i][j] = {dp[i-1][j]+dp[i][j-1]}
//初始值：
	特殊值：第一行和第一列分别初始化，初始化方法相同
	如果第一行有1(障碍)，那么1(障碍)后面的都走不通，所以后面都是0种，如果没有1(障碍)那么后面的都是1种
	如果第一列有1(障碍)，那么1(障碍)后面的都走不通，所以后面都是0种，如果没有1(障碍)那么后面的都是1种
//返回值：
	F(m-1, n-1)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.empty()){
            return 0;
        }
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        
        //初始值：第一列如果有1，那么第一列后面的都是走不通都是0种
        for(int i = 0; i < row; i++){
            if(obstacleGrid[i][0] == 1){
                break;
            }
            else{
                dp[i][0] = 1;
            }
        }
        //初始值：第一行如果有1，那么第一行后面的都是走不通的都是0种
        for(int j = 0 ; j < col; j++){
            if(obstacleGrid[0][j] == 1){
                break;
            }
            else{
                dp[0][j] = 1;
            }
        }
        
        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
				//F(i,j):如果obstacleGrid[i][j] == 1,则dp[i][j] = 0;	//走不通
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else{
					//否则dp[i][j] = {dp[i-1][j]+dp[i][j-1]}
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[row-1][col-1];
    }
};