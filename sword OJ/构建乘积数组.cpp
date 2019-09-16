//笨方法：
class Solution {
public:
    long long Mul(const vector<int>& A, int index){
        long long ret = 1;
        for(int i = 0; i < A.size(); i++){
            if(i == index){
                continue;
            }else{
                ret *= A[i];
            }
        }
        return ret;
    }
    vector<int> multiply(const vector<int>& A) {
        vector<int> B;
        B.resize(A.size());
        for(int i = 0; i < B.size(); i++){
            B[i] = Mul(A, i);
        }
        return B;
    }
};

//O(n)的做法
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B0(A.size(), 1);
        vector<int> B1(A.size(), 1);
        //上三角
        for(int i = 1; i < A.size(); i++){
            B0[i] = B0[i - 1] * A[i - 1];
        }
        //下三角
        for(int i = A.size() - 2; i >= 0; i--){
            B1[i] = B1[i + 1] * A[i + 1];
        }
        vector<int> B(A.size());
        for(int i = 0; i < B.size(); i++){
            B[i] = B0[i] * B1[i];
        }
        return B;
    }
};