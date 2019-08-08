题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
//思路：二叉搜索树的特性是左子树比根小，右子树比根大
//从第一个位置往后找，直到找到比根大的位置index，index之前就是左子树，index之后就是右子树
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size() == 0){
            return false;
        }
        if(sequence.size() == 1){
            return true;
        }
        return isPostorderTravelsal(sequence, 0, sequence.size()-1);
    }
    bool isPostorderTravelsal(vector<int> que, int begin, int end){
        if(begin >= end){
            return true;
        }
        int i = begin;
        while(que[i] < que[end]){
            ++i;
        }
        for(int j = i; j < end; j++){
            if(que[j] < que[end]){
                return false;
            }
        }
        return isPostorderTravelsal(que, 0, i-1)
            && isPostorderTravelsal(que, i+1, end);
    }
};