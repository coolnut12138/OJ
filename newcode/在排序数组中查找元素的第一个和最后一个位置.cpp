#include <iostream>
#include <vector>
using namespace std;

void FindIndex(vector<int> v, int num, int& min, int& max){
    int n = v.size();
    int left = 0;
    int right = n - 1;
    while(left < right){
        int mid = left + (right - left) / 2;
        if(v[mid] >= num){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    if(v[left] != num){
        return;
    }
    min = left;
    right = n;
    while(left < right){
        int mid = left + (right - left) / 2;
        if(v[mid] <= num){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    max = left - 1;
}

int main()
{
    int num;
    while(cin >> num){
        vector<int> v;
        string str;
        cin >> str;
        int j = 0;
        for(int i = 0; i < str.size(); i++){
            string tmp;
            if(str[i] == ','){
                tmp = str.substr(j, i - j);
                j = i + 1;
                v.push_back(atoi(tmp.c_str()));
            }
        }
        v.push_back(atoi(str.substr(j, str.size() - j).c_str()));
        
        int minIndex = -1;
        int maxIndex = -1;
        FindIndex(v, num, minIndex, maxIndex);
        cout << minIndex << ',' << maxIndex << endl;
    }
    return 0;
}