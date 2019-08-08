https://www.nowcoder.com/practice/6aa9e04fc3794f68acf8778237ba065b?tpId=13&tqId=11186&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
题目描述
把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

//思路：由于第一个丑数是1，且丑数的质数只有2，3，5，所以从1开始乘以2，3，5；
//2，3，5再去分别乘以2，3，5会得到4,6,10,6,9,15,10,15,25九个丑数,
//但是这样会有重复的，所以维护三个下标，分别记录乘以2、乘以3、乘以5的数列
//每次取三个数列中最小的数放入数组得到的就是有序的丑数数组。
class Solution {
public:
    //丑数的排列：1，2，3，4，5，6，8，9，10...
    int GetUglyNumber_Solution(int index) {
        if(index < 7){
            return index;
        }
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;
        int num = 1;
        vector<int> arr;
        arr.push_back(num);
        while(arr.size() < index){
            num = min(arr[p2]*2, min(arr[p3]*3, arr[p5]*5));
            if(num == arr[p2]*2)
                p2++;
            if(num == arr[p3]*3)
                p3++;
            if(num == arr[p5]*5)
                p5++;
            arr.push_back(num);
        }
        return arr[arr.size()-1];
    }
};