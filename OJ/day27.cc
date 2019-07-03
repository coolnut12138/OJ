//不使用四则运算计算加法
//方法一：
class Solution {
public:
    int Add(int num1, int num2)
    {
        //自增自减
        if(num1 > 0){
            while(num1--){
                num2++;
            }
        }
        else if(num1 < 0){
            while(num1++){
                num2--;
            }
        }
        return num2;
    }
};
//方法二：位运算
1、两个数异或：相当于每一位相加，而不考虑进位；
2、两个数相与，并左移一位：相当于求得进位；
3、将上述两步的结果相加
class Solution {
public:
    int Add(int num1, int num2)
    {
        while(num2 != 0){
            int sum = num1 ^ num2;    //异或求和
            int carry = (num1 & num2) << 1;//相与左移一位得进位
            num1 = sum;
            num2 = carry;
        }
        return num1;
    }
};


//给定三条边，判断是不是三角形
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    while(cin >> a >> b >> c){
        if((a + b > c) && (a + c > b) && (b + c > a) && (abs(a - b) < c) && (abs(a - c) < b) && (abs(b - c) < a)){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}