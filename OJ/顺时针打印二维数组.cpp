class Printer {
public:
    vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
        // write code here
        vector<int> res;
        if(n <= 0 || m <= 0){
            return res;
        }
        int left = 0;
        int right = m - 1;
        int up = 0;
        int down = n - 1;
        while(left <= right && up <= down){    
            for(int i = left; i <= right; ++i){    //向右
                res.push_back(mat[up][i]);
            }
            if(up < down){
                for(int i = up + 1; i <= down; ++i){    //向下
                    res.push_back(mat[i][right]);
                }
            }
            if(up < down && left < right){    //向左，防止单行
                for(int i = right - 1; i >= left; --i){
                    res.push_back(mat[down][i]);
                }
            }
            if(up < down && left < right){    //向上，防止单列
                for(int i = down - 1; i > up; --i){
                    res.push_back(mat[i][left]);
                }
            }
            left++;
            right--;
            up++;
            down--;
        }
        return res;
    }
};