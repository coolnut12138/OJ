https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?tpId=13&tqId=11180&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> ret;
        if(str.empty()){
            return ret;
        }
        do
        {
            ret.push_back(str);
        }while(next_permutation(str.begin(), str.end()));
        return ret;
    }
};