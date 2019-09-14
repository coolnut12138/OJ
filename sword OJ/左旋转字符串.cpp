//思路：用队列来模拟实现过程，空间时间复杂度都是O(n)
class Solution {
public:
    string LeftRotateString(string str, int n) {
        queue<char> q;
        for(int i = 0; i < str.size(); i++){
            q.push(str[i]);
        }
        for(int i = 0; i < n; i++){
            char tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        string ret = "";
        int size = q.size();
        for(int i = 0; i < size; i++){
            ret += q.front();
            q.pop();
        }
        return ret;
    }
};

//思路二：将前n个字符串拿出来left，和n之后的字符串拿出来right，再把left拼接到right后面形成新字符串即所求
class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.empty()){
            return str;
        }
        string left = str.substr(0, n);
        string right = str.substr(n);
        string ret = right + left;
        return ret;
    }
};