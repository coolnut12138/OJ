你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。

空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。

示例 1:

输入: 二叉树: [1,2,3,4]
       1
     /   \
    2     3
   /    
  4     

输出: "1(2(4))(3)"

解释: 原本将是“1(2(4)())(3())”，
在你省略所有不必要的空括号对之后，
它将是“1(2(4))(3)”。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-string-from-binary-tree

class Solution {
public:
    string tree2str(TreeNode* t) {
        string str = "";
        if(t == nullptr){
            return str;
        }
        if(t->left == nullptr && t->right == nullptr){
            return (str += (to_string(t->val)));
        }
        str += (to_string(t->val));
        //左边的空括号不能省略
        str += ("(" + tree2str(t->left) + ")");
        //右子树的空括号可以省略
        if(t->right != nullptr){
            str += ("(" + tree2str(t->right) + ")");
        }
        return str;
    }
};