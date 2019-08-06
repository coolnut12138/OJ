在大小为 2N 的数组 A 中有 N+1 个不同的元素，其中有一个元素重复了 N 次。

返回重复了 N 次的那个元素。

 

示例 1：

输入：[1,2,3,3]
输出：3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-repeated-element-in-size-2n-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_map<int, int> ump;
        for(const auto& e : A){
            ump[e]++;
        }
        
        for(const auto& e : ump){
            if(e.second == A.size()/2){
                return e.first;
            }
        }
        return 0;
    }
};