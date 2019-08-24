[编程题]素数对
给定一个正整数，编写程序计算有多少对质数的和等于输入的这个正整数，并输出结果。输入值小于1000。
如，输入为10, 程序应该输出结果为2。（共有两对质数的和为10,分别为(5,5),(3,7)）

输入描述:
输入包括一个整数n,(3 ≤ n < 1000)

输出描述:
输出对数

输入例子1:
10
输出例子1:
2

#include <iostream>
#include <vector>
using namespace std;

void producePrime(vector<int>& prime){
    for(int i = 2; i < 1000; i++){
        bool flag = true;
        for(int j = 2; j < i; j++){
            if(i % j == 0){
                flag = false;
                break;
            }
        }
        if(flag){
            prime.push_back(i);
        }
    }
}

int countPrimePair(int num, vector<int> prime){
    int count = 0;
    for(int i = 0; i < prime.size(); i++){
        for(int j = 0; j <= i; j++){
            if(prime[i] + prime[j] == num){
                ++count;
            }
        }
    }
    return count;
}

int main()
{
    int num;
    vector<int> prime;
	//产生素数数组
    producePrime(prime);
    while(cin >> num){
        if(num <= 3){
            cout << "0" << endl;
            break;
        }
		//计算有几对符合条件的素数
        cout << countPrimePair(num, prime) << endl;
    }
    return 0;
}