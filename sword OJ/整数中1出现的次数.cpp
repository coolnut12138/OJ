题目描述
求出1~13 的整数中1出现的次数,并算出100~1300 的整数中1出现的次数？
为此他特别数了一下1~13 中包含1的数字有1、10、11、12、13因此共出现6次,
但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,
可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）
//法一：遍历法
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count = 0;
        if(n <= 0){
            return 0;
        }
        for(int i = 1; i <= n; i++){
            int tmp = i;
            while(tmp){
                if(tmp % 10 == 1){
                    ++count;
                }
                tmp /= 10;
            }
        }
        return count;
    }
};