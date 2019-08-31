https://www.nowcoder.com/practice/c451a3fd84b64cb19485dad758a55ebe?tpId=13&tqId=11194&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
题目描述
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16 的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22 。
现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
输出描述:
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
class Solution {
public:
    //利用窗口大小解决问题
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        int left = 1;
        int right = 2;
        while(left < right){
            //等差数列求和公式 cursum = (a1 + an)*n/2
            int cursum = (left+right)*(right-left+1)/2;
            //求得的和等于sum就将这些值存起来
            if(cursum == sum){
                vector<int> tmp;
                for(int i = left; i <= right; i++){
                    tmp.push_back(i);
                }
                res.push_back(tmp);
                left++;
            }
            //求得的值大于sum，将窗口左沿右移
            else if(cursum > sum){
                left++;
            }else{
                //求得的值小于sum，将窗口右沿右移
                right++;
            }
        }
        return res;
    }
};