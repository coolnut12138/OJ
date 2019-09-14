class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        //找出0
        //数组元素不重复且只有五个元素
        //数组中最大的元素减最小的元素的差为4
        if(numbers.size() != 5){
            return false;
        }
        sort(numbers.begin(), numbers.end());
        //是否重复和统计0的个数
        int zeroCount = 0;
        for(int i = 0; i < 5; i++){
            if(numbers[i] == 0){
                zeroCount++;
            }
            if(i < 4){
                if(numbers[i] != 0 && numbers[i] == numbers[i + 1]){
                    return false;
                }
            }
        }
        int Min = numbers[zeroCount];
        int Max = numbers[4];
        if(Max - Min < 5){
            return true;
        }
        return false;
    }
};



class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() != 5){
            return false;
        }
        int Min = 14;
        int Max = -1;
        //判断是否重复
        unordered_map<int, int> mp;
        for(int i = 0; i < numbers.size(); i++){
            mp[numbers[i]]++;
            if(numbers[i] == 0){
                continue;
            }
            if(mp[numbers[i]] > 1){
                //除0外，如果有重复则不满足条件
                return false;
            }
            if(numbers[i] < Min){
                Min = numbers[i];
            }
            if(numbers[i] > Max){
                Max = numbers[i];
            }
        }
        if(Max - Min < 5){
            return true;
        }
        return false;
    }
};