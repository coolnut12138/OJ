给定两个句子 A 和 B 。 （句子是一串由空格分隔的单词。每个单词仅由小写字母组成。）

如果一个单词在其中一个句子中只出现一次，在另一个句子中却没有出现，那么这个单词就是不常见的。

返回所有不常用单词的列表。

您可以按任何顺序返回列表。

 

示例 1：

输入：A = "this apple is sweet", B = "this apple is sour"
输出：["sweet","sour"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/uncommon-words-from-two-sentences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution {
public:
    void Partition(string str, unordered_map<string, int>& mp){
        string tmp;
        int start = 0;
        int end = 0;
        while(end != -1){
            end = str.find(" ", start);
            tmp = str.substr(start, end-start);
            mp[tmp]++;
            start = end + 1;
        }
    }
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> ump;
        Partition(A, ump);
        Partition(B, ump);
        
        vector<string> ret;
        for(const auto& e : ump){
            if(e.second == 1){
                ret.push_back(e.first);
            }
        }
        return ret;
    }
};