//斐波那契数列定义：F(n) = F(n-1) + F(n-2) , n>=2 
//F(1) == 1 F(2) == 1
//递归写法：时间复杂度是O(2^n),是指数增长的形式，效率低，当n达到一定程度会栈溢出
int Fibonacci(int n) {
    if(n <= 0){
        return 0;
    }
    if(n == 1 || n == 2){
        return 1;
    }
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

//动态规划，申请一个数组保存之前的数
//状态：F(n)
//状态递推：F(n) = F(n-1) + F(n-2);
//初始值：F(1) = F(2) = 1;
//返回值：F(N)
int Fibonacci(int n) {
		//初始值
        if(n == 0){
            return 0;
        }
        if(n == 1 || n == 2){
            return 1;
        }
        //申请一个数组保存子问题的解
        int arr[1024];
        arr[0] = 0;
        arr[1] = 1;
        for(int i = 2; i < n + 1; i++){
			//F(n) = F(n-1) + F(n-2)
            arr[i] = arr[i-1] + arr[i-2];
        }
        return arr[n];
    }
	
//但是上面这个的空间复杂度是O(n),这个题只是求n的斐波那契，所以只需要保存前两项的值即可
int Fibonacci(int n) {
        if(n == 0){
            return 0;
        }
        if(n == 1 || n == 2){
            return 1;
        }
        int a = 1;
        int b = 1;
        int res = 0;
        for(int i = 3; i <= n; i++){
            res = a + b;
            a = b;
            b = res;
        }
        return res;
    }