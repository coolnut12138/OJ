//思路一：用链表模拟圆环，模拟实现数数的过程
class Solution {
public:
    //用链表模拟圆圈
    int LastRemaining_Solution(int n, int m)
    {
        if(n <= 0 || m <= 0){
            return -1;
        }
        list<int> child;
        //将所有元素放进链表
        for(int i = 0; i < n; i++){
            child.push_back(i);
        }
        
        list<int>::iterator cur = child.begin();
        while(child.size() > 1){
            //走m - 1步，找要删除的结点
            for(int i = 0; i < m - 1; i++){
                ++cur;
                if(cur == child.end()){
                    cur = child.begin();
                }
            }
            //找到要删除的结点，删除，要考虑迭代器失效问题
            list<int>::iterator next = ++cur;
            if(next == child.end()){
                next = child.begin();
            }
            --cur;
            child.erase(cur);
            cur = next;
        }
        return *cur;
    }
};