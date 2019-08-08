一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
//思路：使用unordered_map将每个元素出现的次数存储下来，再遍历一遍哈希表将出现一次的数字记录即可
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        unordered_map<int, int> ump;
        for(const auto& e : data){
            ump[e]++;
        }
        vector<int> ret;
        for(const auto& e : ump){
            if(e.second == 1){
                ret.push_back(e.first);
            }
        }
        *num1 = ret[0];
        *num2 = ret[1];
    }
};

//思路二：异或的思想
//因为只有两个数字是只出现一次的，其他数字都是出现两次的，所以将所有数字异或一遍。
//得到那两个数字的异或结果。
//找到异或结果的最后一位是1的地方，用这个1来区分两个数
//把这一位是1的数分为一组，这一位是0的数分为一组
//两组数分别异或得到最终两个数字
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size() < 2){
            return;
        }
        
        int tmp = data[0];
        for(int i = 1; i < data.size(); i++){
            tmp ^= data[i];
        }
        
        int index = 0;
        while(((tmp >> index) & 1) == 0){
            index++;
        }
        *num1 = *num2 = 0;
        for(int i = 0; i < data.size(); i++){
            if(((data[i] >> index) & 1) == 0){
                *num1 ^= data[i];
            }else{
                *num2 ^= data[i];
            }
        }
    }
};