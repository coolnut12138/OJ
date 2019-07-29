https://www.nowcoder.com/practice/5f3b7bf611764c8ba7868f3ed40d6b2c?tpId=46&tqId=29041&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
//字符串分割
//题目描述
//给定一个字符串和一个词典dict，确定s是否可以根据词典中的词分成一个或多个单词。
//比如，给定
//s = "leetcode"
//dict = ["leet", "code"]
//返回true，因为"leetcode"可以被分成"leet code"

//思路：动态规划
	//子状态：前1，2，3，。。。，n个字符能否根据词典中的词被成功分词
	//F(i)：前i个字符能否根据词典中的词被成功分词
//状态递推：
	//F(i)：true{j<i && F(j) && substr[j+1, i]能在词典中找到} or false
	//在j < i中，只要能找到一个F(j)为true，并且从j+1到i的字符能在词典中找到，则F(i)=true;
//初始值：
	//初始值不确定，引入一个无关的空状态。F(0) = true;
//返回结果：
	//F(n)

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(s.empty() || dict.empty()){
            return false;
        }
        
		//获取词典中单词的最大长度
        int maxLength = 0;
        for(const auto& e : dict){
            if(e.size() > maxLength){
                maxLength = e.size();
            }
        }
        
        vector<bool> res(s.size() + 1, false);
        res[0] = true;
        for(int i = 1; i <= s.size(); i++){
            for(int j = i - 1; j >= 0; j--){
				//最小子串的长度大于maxLenth，跳过
                if((i-j) > maxLength){
                    break;
                }
                
				//F(i): true{j<i && F(j) && substr[j+1, i]能在词典中找到} or false
				//第j+1个字符的索引为j
                if(res[j] && dict.find(s.substr(j, i-j)) != dict.end()){
                    res[i] = true;
                    break;
                }
            }
        }
        return res[s.size()];
    }
};