链接：https://www.nowcoder.com/questionTerminal/05f97d9b29944c018578d98d7f0ce56e?toCommentId=1092721
来源：牛客网

Web系统通常会频繁地访问数据库，如果每次访问都创建新连接，性能会很差。为了提高性能，架构师决定复用已经创建的连接。当收到请求，并且连接池中没有剩余可用的连接时，系统会创建一个新连接，当请求处理完成时该连接会被放入连接池中，供后续请求使用。
现在提供你处理请求的日志，请你分析一下连接池最多需要创建多少个连接。
输入描述:
输入包含多组数据，每组数据第一行包含一个正整数n（1≤n≤1000），表示请求的数量。

紧接着n行，每行包含一个请求编号id（A、B、C……、Z）和操作（connect或disconnect）。
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    while(cin >> n){
        string id, ope;
        vector<pair<string, string>> v;
        for(int i = 0; i < n; i++){
            cin >> id >> ope;
            v.push_back(make_pair(id, ope));
        }
        
        int count = 0;    //当前连接数
        int max = 0;        //最大连接数
        for(int i = 0; i < n; i++){
            if(v[i].second == "connect"){    //如果是connect，则连接数+1
                count++;    
            }else{
                max = max > count ? max : count;
                count--;    //如果不是connect，那么连接数-1
            }
        }
        cout << max << endl;
    }
    return 0;
}