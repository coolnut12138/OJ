//先反转整个句子，再反转每个单词
class Solution {
public:
    void ReverseWord(string& word, int left, int right) {
        while (left < right) {
            swap(word[left], word[right]);
            left++;
            right--;
        }
    }
    string ReverseSentence(string str) {
        int left = 0;
        int right = str.size() - 1;
        while (left < right) {
            swap(str[left], str[right]);
            left++;
            right--;
        }
        int j = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ') {
                ReverseWord(str, j, i - 1);
                j = i + 1;
            }
        }
        ReverseWord(str, j, str.size() - 1);
        return str;
    }
};

//思路二：tmp记录单词 ret记录句子
class Solution {
public:
    string ReverseSentence(string str) {
        string ret = "";    //记录整个句子
        string tmp = "";    //记录每个单词
        for(size_t i = 0; i < str.size(); i++){
            if(str[i] != ' '){
                tmp += str[i];
            }else{
                ret = " " + tmp + ret;	//将单词放到当前句子的前面，记得有空格
                tmp = "";
            }
        }
        if(!tmp.empty()){	//最后一个单词单独处理
            ret = tmp + ret;
        }
        return ret;
    }
};