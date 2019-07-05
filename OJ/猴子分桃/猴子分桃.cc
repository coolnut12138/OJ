#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long n;    //猴子数
    while(cin >> n){
        if (n == 0)
            break;
        else{
            long long sum1 = pow(5, n) - 4;	//最少需要的桃子数
            long long sum2 = pow(4, n) + n - 4;	//老猴最少能得到桃子数
            cout << sum1 << " " << sum2 << endl;
        }
    }
    return 0;
}