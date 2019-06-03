//输入年月日，计算这天距离第一天有多少天
#include <iostream>
using namespace std;

int Getday(int year, int month, int day)
{
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((year % 4 == 0 && year && 100 != 0) || (year % 400 == 0)){
        months[1] += 1;
    }
    int ret = 0;
    for(int i = 0; i < month - 1; i++){
        ret += months[i];
    }
    ret += day;
    return ret;
}

int main()
{
    int year, month, day;
    while(cin >> year >> month >> day){
        cout << Getday(year, month, day) << endl;
    }
    return 0;
}