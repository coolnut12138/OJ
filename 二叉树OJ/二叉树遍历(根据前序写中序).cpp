题目描述
编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。 
例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。
建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。

#include <iostream>
#include <string>
using namespace std;
string pre;
int i;

struct Node
{
    char val;
    struct Node* left;
    struct Node* right;
    Node(char c)
        :val(c)
        ,left(nullptr)
        ,right(nullptr)
        {}
};

Node* CreateTree()
{
    char c = pre[i++];
    if(c == '#'){
        return nullptr;
    }
    struct Node* root = new Node(c);
    root->left = CreateTree();
    root->right = CreateTree();
    return root;
}

void InorderTravelsal(struct Node* root)
{
    if(root == nullptr){
        return;
    }
    InorderTravelsal(root->left);
    cout << root->val << " ";
    InorderTravelsal(root->right);
}

int main()
{
    while(cin >> pre){
        i = 0;
        struct Node* root = CreateTree();
        InorderTravelsal(root);
        cout << endl;
    }
}