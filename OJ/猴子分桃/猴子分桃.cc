#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long n;    //������
    while(cin >> n){
        if (n == 0)
            break;
        else{
            long long sum1 = pow(5, n) - 4;	//������Ҫ��������
            long long sum2 = pow(4, n) + n - 4;	//�Ϻ������ܵõ�������
            cout << sum1 << " " << sum2 << endl;
        }
    }
    return 0;
}