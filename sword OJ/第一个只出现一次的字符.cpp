题目描述
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.

//思路：使用哈希map存储字符和出现次数的键值对
//然后遍历字符串，找到对应字符出现次数为1的字符，不能遍历哈希map，因为存储进去后已经乱序了
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char, int> ump;
        for(const auto& e : str){
            ump[e]++;
        }
        
        for(int i = 0; i < str.size(); i++){
            if(ump[str[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};