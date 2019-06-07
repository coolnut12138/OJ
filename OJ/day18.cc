牛客：求兔子总数
#include <iostream>
using namespace std;

int getTotalCount(int month)
{
    int num = 0;
    if(month <= 2){
        return 1;
    }
    return getTotalCount(month - 1) + getTotalCount(month - 2);
}

int main()
{
    int month = 0;
    while(cin >> month){
        cout << getTotalCount(month) << endl;
    }
    return 0;
}