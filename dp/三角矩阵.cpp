https://www.nowcoder.com/practice/2b7995aa4f7949d99674d975489cb7da?tpId=46&tqId=29060&tPage=2&rp=2&ru=/ta/leetcode&qru=/ta/leetcode/question-rankin
给定一个三角矩阵，找出自顶向下的最短路径和，每一步可以移动到下一行的相邻数字。
比如给定下面一个三角矩阵，自顶向下的最短路径和为11
[
   [2],
  [3,4],
 [6,5,7],
[4,1,8,3]
]
//思路：动态规划
状态：
	子状态：从(0,0)到(1,0)(1,1)(2,0)...(n,n)的最短路径和
		F(i,j):表示从(0,0)到(i,j)的最短路径和
状态递推：
	F(i,j) = min{F[i-1][j-1], F[i-1][j]} + triangle[i][j];
初始状态：
	F[0][0] = triangle[0][0];
返回值：
	最后一行中最小的值
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.empty()){
            return 0;
        }
        
        int n = triangle.size();
		//初始状态F[0][0] = triangle[0][0]
        vector<vector<int>> dp(triangle);
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= i; j++){
				//边界情况
                if(j == 0){
                    dp[i][j] = dp[i-1][j];
                }
                else if(j == i){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
					//递推式：F(i,j) = min{F[i-1][j-1], F[i-1][j]} + triangle[i][j];
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]);
                }
                dp[i][j] += triangle[i][j];
            }
        }
        
		//返回最后一行的最小值
        int res = dp[n-1][0];
        for(int i = 1; i < n; i++){
            res = res > dp[n-1][i] ? dp[n-1][i] : res;
        }
        return res;
    }
};

//方法二：动态规划(逆向思维)：从最后一行往前考虑，每次取最小值，到F[0][0]即最小值
状态：
	子状态：从(n,n)(n,n-1)(n,n-2)...(1,0)(1,1)(0,0)到最后一行的最短路径
	F(i,j):从(i,j)到最后一行的最短路径
状态递推：
	F(i,j) = min{F(i+1)(j), F(i+1)(j+1)} + triangle[i][j];
初始值：
	最后一行初始化为triangle的最后一行
返回结果：
	F[0][0]
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.empty()){
            return false;
        }
        
		//初始化最后一行
        vector<vector<int>> rdp(triangle);
        int n = triangle.size();
		//从倒数第二行开始往前计算
        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
				//递推式：F(i,j) = min{F(i+1)(j), F(i+1)(j+1)} + triangle[i][j];
                rdp[i][j] = min(rdp[i+1][j+1], rdp[i+1][j]) + triangle[i][j];
            }
        }
        return rdp[0][0];
    }
};