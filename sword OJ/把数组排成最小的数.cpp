题目描述
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
//思路：仿函数对象先将数组中按从小到大排列，然后将每个元素按序相加即可
class Solution {
public:
    static bool cmp(int a, int b){
        string A = to_string(a) + to_string(b);
        string B = to_string(b) + to_string(a);
        return A < B;
    }
    string PrintMinNumber(vector<int> numbers) {
        int size = numbers.size();
        if(size <= 0){
            return "";
        }
        sort(numbers.begin(), numbers.end(), cmp);
        
        string ret = "";
        for(const auto& e : numbers){
            ret += to_string(e);
        }
        return ret;
    }
};