链接：https://www.nowcoder.com/questionTerminal/16fa68271ee5448cafd504bb4a64b482?toCommentId=1092688
来源：牛客网
nowcoder要和朋友交流一些敏感的信息，例如他的电话号码等。因此他要对这些敏感信息进行混淆，比如在数字中间掺入一些额外的符号，让它看起来像一堆乱码。
现在请你帮忙开发一款程序，解析从nowcoder那儿接收到的信息，读取出中间有用的信息。

输入描述:
输入有多行。

每一行有一段经过加密的信息（其中可能包含空格），并且原始信息长度不确定。


输出描述:
输出每段信息中数字信息。

// write your code here cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string code;
    while(getline(cin, code)){
        string res = "";
        for(size_t i = 0; i < code.size(); i++){
            if(code[i] <= '9' && code[i] >= '0'){
                res += code[i];
            }
        }
        cout << res <<endl;
    }
    return 0;
}