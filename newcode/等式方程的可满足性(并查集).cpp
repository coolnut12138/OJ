给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为 4，
并采用两种不同的形式之一："a==b" 或 "a!=b"。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。

只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。 

示例 1：
输入：["a==b","b!=a"]
输出：false
解释：如果我们指定，a = 1 且 b = 1，
那么可以满足第一个方程，但无法满足第二个方程。没有办法分配变量同时满足这两个方程。

示例 2：
输出：["b==a","a==b"]
输入：true
解释：我们可以指定 a = 1 且 b = 1 以满足满足这两个方程。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/satisfiability-of-equality-equations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    class UnionFindSet
    {
    public:
        UnionFindSet(size_t size)
            :_ufs(size, -1)
            {}
        
        int FindRoot(int index){
            while(_ufs[index] >= 0){
                index = _ufs[index];
            }
            return index;
        }
        
        bool Union(int x1, int x2){
            int root1 = FindRoot(x1);
            int root2 = FindRoot(x2);
            
            if(root1 == root2){
                return false;
            }
            
            _ufs[root1] += _ufs[root2];
            _ufs[root2] = root1;
            
            return true;
        }
        
        size_t Count()
        {
            size_t size = 0;
            for(const auto& e : _ufs){
                if(e < 0){
                    size++;
                }
            }
            return size;
        }
    private:
        vector<int> _ufs;
    };
    
    bool equationsPossible(vector<string>& equations) {
        UnionFindSet ufs(26);
        for(const auto& e : equations){
            if(e[1] == '='){
                ufs.Union(e[0] - 'a', e[3] - 'a');
            }
        }
        
        for(const auto& e : equations){
            if(e[1] == '!'){
                if(ufs.FindRoot(e[0] - 'a') == ufs.FindRoot(e[3] - 'a')){
                    return false;
                }
            }
        }
        return true;
    }
};