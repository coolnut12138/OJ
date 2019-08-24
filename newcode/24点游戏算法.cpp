链接：https://www.nowcoder.com/questionTerminal/fbc417f314f745b1978fc751a54ac8cb?toCommentId=142189
来源：牛客网

问题描述：给出4个1-10的数字，通过加减乘除，得到数字为24就算胜利
输入：
4个1-10的数字。[数字允许重复，但每个数字仅允许使用一次，测试用例保证无异常数字]
输出：
true or false


输入描述:
输入4个int整数



输出描述:
返回能否得到24点，能输出true，不能输出false
#include <iostream>
#include <vector>
using namespace std;

bool is24(vector<double>& arr, int total, double result){
    if(arr.empty()){
        return total == result;
    }
    
    for(int i = 0; i < arr.size(); i++){
        vector<double> b(arr);
        b.erase(b.begin() + i);
        if(is24(b, total, result + arr[i]) || 
          is24(b, total, result - arr[i]) || 
          is24(b, total, result * arr[i]) || 
          is24(b, total, result / arr[i])){
            return true;
        }
    }
    return false;
}

int main()
{
    vector<double> arr(4, 0);
    while(cin >> arr[0] >> arr[1] >> arr[2] >> arr[3]){
        if(is24(arr, 24, 0)){
            cout << "true" << endl;
        }else{
            cout << "false" << endl;
        }
    }
    return 0;
}