给定一个整数数组，判断是否存在重复元素。

如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

示例 1:

输入: [1,2,3,1]
输出: true
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(const auto& e : nums){
            mp[e]++;
        }
        
        for(const auto& e : mp){
            if(e.second >= 2){
                return true;
            }
        }
        return false;
    }
};


///////////////////////////////////////////////
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(const auto& e : nums){
            if(s.find(e) == s.end()){
                s.insert(e);
            }else{
                return true;
            }
        }
        return false;
    }
};