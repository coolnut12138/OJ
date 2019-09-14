public class Solution {
    public int Add(int num1,int num2) {
        int sum;
        int carry;
        while(num2 != 0){
            //异或计算不进位的加
            sum = num1 ^ num2;
            //与运算可以求出要进位的位(因为两个位都为1才能进位),再左移1位(左移一位表示要加到哪一位)
            carry = (num1 & num2) << 1;
            num1 = sum;
            num2 = carry;
        }
        return num1;
    }
}