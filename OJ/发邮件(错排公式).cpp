链接：https://www.nowcoder.com/questionTerminal/95e35e7f6ad34821bc2958e37c08918b?orderByHotValue=2&page=1&onlyReference=false
来源：牛客网

NowCoder每天要给很多人发邮件。有一天他发现发错了邮件，把发给A的邮件发给了B，把发给B的邮件发给了A。于是他就思考，要给n个人发邮件，在每个人仅收到1封邮件的情况下，有多少种情况是所有人都收到了错误的邮件？
即没有人收到属于自己的邮件。
// write your code here cpp
#include <iostream>
using namespace std;

long long GetCount(int n){
    long long arr[21] = {0};
    arr[2] = 1;
    for(int i = 3; i < 21; i++){
        arr[i] = (i-1)*(arr[i-1] + arr[i-2]);
    }
    return arr[n];
}

int main()
{
    int n;
    while(cin >> n){
        cout << GetCount(n) << endl;
    }
    return 0;
}