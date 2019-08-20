链接：https://www.nowcoder.com/questionTerminal/2a3dc06f337d4a2ba41d25c688f95e2f
来源：牛客网

av394281 中，充满威严的蕾米莉亚大小姐因为触犯某条禁忌，被隙间妖怪八云紫（紫m……èi）按住头在键盘上滚动。
同样在弹幕里乱刷梗被紫姐姐做成罪袋的你被指派找到大小姐脸滚键盘打出的一行字中的第 `k` 个仅出现一次的字。
(为简化问题，大小姐没有滚出 ascii 字符集以外的字)



输入描述:
每个输入都有若干行，每行的第一个数字为`k`，表示求第`k`个仅出现一次的字。然后间隔一个半角空格，之后直到行尾的所有字符表示大小姐滚出的字符串`S`。


输出描述:
输出的每一行对应输入的每一行的答案，如果无解，输出字符串`Myon~`

(请不要输出多余的空行）

为了方便评测，如果答案存在且为c，请输出[c]
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    string str;
    while(getline(cin, str)){
        int i = 0;
        for(; i < str.size(); i++){
            if(str[i] == ' '){
                break;
            }
        }
		//将数字和字符串分离
        int n = stoi(str.substr(0, i));
        string sstr = str.substr(i+1, str.size());
        
        unordered_map<char, int> ump;
        string ret = "";
        for(const auto& e : sstr){
            ump[e]++;
        }
        
		//此处因为是顺序找到第k个，所以要按照字符串的顺序找
        for(int i = 0; i < sstr.size(); i++){
            if(ump[sstr[i]] == 1 && --n == 0){
                ret = sstr[i];
                break;
            }
        }
        
        if(ret == ""){
            cout << "Myon~" << endl;
        }else{
            cout << "[" << ret << "]" << endl;
        }
    }
    return 0;
}