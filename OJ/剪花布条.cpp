// write your code here cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, t;
    while(cin >> s >> t){
        int count = 0;
        size_t len = t.size();
        while(!s.empty()){
            if(s[0] != t[0]){	//如果第一个字母不相等，就去掉头
                s = s.substr(1);
            }else{	//第一个字母相等开始往后比
                size_t i = 0;
                for(; i < len; i++){
                    if(s[i] != t[i]){	//如果比到第二个字符串的第 i 个不相等，就去掉前 i 个字符
                        s = s.substr(i);
                        break;
                    }
                }
                if(i == len){
                    s = s.substr(len); //如果有一个完整的第二个字符串，就把第一个字符串的前第二个字符串的长度的字符去掉
                    ++count;			//计数+1；
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}