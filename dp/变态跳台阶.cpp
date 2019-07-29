我们先梳理几个底层有多少种跳法： 
1层台阶， 1 1种
2层台阶，11，2 2种
3层台阶，111，12，21，3 4种
4层台阶，1111，112，121，13，211，22，31，4 8种
5层台阶，11111，1112，1121，113，1211，122，131，14，2111，212，221，23，311，32，41，5 16种
f(n) = f(n - 1) + f(n - 2) + ... + f(2) + f(1) + 1。例如：

当跳1级台阶时，f(1) = 1;
当跳2级台阶时，f(2) = f(1) + 1 = 2;
当跳3级台阶时，f(3) = f(2) + f(1) + 1 = 4;
当跳4级台阶时，f(4) = f(3) + f(2) + f(1) + 1 = 8;
。。。。。。。。。。。。。。。。。。。。。
f(n) = f(n - 1) + f(n - 2) + ... + f(2) + f(1) + 1
f(n - 1) = f(n - 2) + ... + f(2) + f(1) + 1
===》f(n) - f(n - 1) = f(n - 1) 
==》f(n) = 2 * f(n - 1)
即当 
	n <= 0 , 无
	n == 1 , 1
	n > 1, 2 * f(n -1)
	
int jumpFloorII(int number) {
        if(number <= 0){
            return -1;
        }
        else if(number == 1){
            return 1;
        }
        else{
            return 2 * jumpFloorII(number - 1);
        }
    }
	
//排列，从上面的规律可以得出总的排列数为2^(n-1)
	int jumpFloorII(int number) {
        if(number <= 0){
            return 0;
        }
        int total = 1;
        for(int i = 1; i < number; i++){
            total *= 2;
        }
        return total;
    }
//降低时间复杂度为O（1）
	int jumpFloorII(int number) {
        if(number <= 0){
            return 0;
        }
        return 1 << number-1;
    }