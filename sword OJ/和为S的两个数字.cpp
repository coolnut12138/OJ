//前后下标法。
//从第一个和最后一个开始相加，如果小于sum，left++；如果和大于sum，right--；如果等于sum，left++，right--，寻找下一对
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int left = 0;
        int right = array.size() - 1;
        vector<int> ret;
        while(left < right){
            if(array[left] + array[right] == sum){
                if(!ret.empty()){
                    if(ret[0] * ret[1] > array[left] * array[right]){
                        ret.clear();
                        ret.push_back(array[left]);
                        ret.push_back(array[right]);
                        left++;
                        right--;
                    }
                }else{
                    ret.push_back(array[left]);
                    ret.push_back(array[right]);
                }
                left++;
                right--;
            }
            else if(array[left] + array[right] > sum){
                right--;
            }
            else{
                left++;
            }
        }
        return ret;
    }
};