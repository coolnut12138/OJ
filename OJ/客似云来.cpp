// write your code here cpp
#include <iostream>
#include <vector>

using namespace std;

void Fib(vector<long long>& fib){
    for(size_t i = 2; i < fib.size(); i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

int main()
{
    vector<long long> fib(81, 1);
    Fib(fib);
    int from, to;
    while(cin >> from >> to){
        long long sum = 0;
        for(int i = from; i <= to; i++){
            sum += fib[i - 1];
        }
        cout << sum << endl;
    }
    return 0;
}