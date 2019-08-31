题目描述
统计一个数字在排序数组中出现的次数。
class Solution {
public:
    int BinarySearch(vector<int>& data, double k){
        int start = 0;
        int end = data.size() - 1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(data[mid] > k){
                end = mid - 1;
            }else if(data[mid] < k){
                start = mid + 1;
            }
        }
        return start;
    }
    int GetNumberOfK(vector<int> data ,int k) {
        return BinarySearch(data, k + 0.5) - BinarySearch(data, k - 0.5);
    }
};