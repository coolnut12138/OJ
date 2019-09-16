#include <iostream>
#include <string>
using namespace std;

bool isString(string& s){
    for(size_t i = 0; i < s.size(); i++){
        if(s[i] > '9' || s[i] < '0'){
            return false;
        }
    }
    return true;
}

void Add(string& s1, string& s2){
    size_t len1 = s1.size();
    size_t len2 = s2.size();
    string ret;
    size_t MaxSize = max(len1, len2);
    for(size_t i = 0; i < MaxSize; i++){
        ret += '0';
    }
    if(len1 < len2){
        for(size_t i = 0; i < len2 - len1; i++){
            s1 = '0' + s1;
        }
    }
    else if(len2 < len1){
        for(size_t i = 0; i < len1 - len2; i++){
            s2 = '0' + s2;
        }
    }
    
    for(int i = MaxSize - 1; i >= 0; i--){
        int tmp = int(s1[i]) + int(s2[i]) + int(ret[i]) - 48*3;
        if(tmp < 10){
            ret[i] = tmp + '0';
        }
        else{
            ret[i] = (tmp % 10) + '0';
            char carry = (tmp / 10) + '0';
            if(i == 0){
                ret = carry + ret;
            }else{
                ret[i - 1] = carry;
            }
        }
    }
    cout << ret << endl;
}

int main()
{
    string str1, str2;
    while(cin >> str1 >> str2){
        if(isString(str1) && isString(str2)){
            Add(str1, str2);
        }else{
            cout << "error" << endl;
        }
    }
    return 0;
}