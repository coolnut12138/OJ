它的优势在于只用两种简单操作，入栈和出栈就可以搞定任何普通表达式的运算。其运算方式如下：
如果当前字符为变量或者为数字，则压栈，如果是运算符，则将栈顶两个元素弹出作相应运算，结果再入栈，
最后当表达式扫描完后，栈里的就是结果。

2 + 3 * 4 是一个中缀表达式，操作符在操作数的中间
2 3 4 * +      后缀表达式：操作符位于操作数的尾部

是使用栈来解决这个问题:
    思路：使用一个栈，在vector中如果是数字就将数字压栈，在vector中如果是操作符，就从栈中取出操作数，
	栈顶是右操作数，然后是左操作数，将计算结果压栈，重复上述操作。
// write your code here cpp
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main()
{
    stack<int> ret;
    vector<string> tokens;
    int n;
    while(cin >> n){
        tokens.resize(n);
        for(int i = 0; i < n; i++){
            cin >> tokens[i];
        }
        for(int i = 0; i < n; i++){
            string elem = tokens[i];
            if(elem == "+" || elem == "-" || elem == "*" || elem == "/"){
                int right = ret.top();
                ret.pop();
                int left = ret.top();
                ret.pop();
                if(elem == "+")
                    ret.push(left + right);
                if(elem == "-")
                    ret.push(left - right);
                if(elem == "*")
                    ret.push(left * right);
                if(elem == "/")
                    ret.push(left / right);
            }else{
                ret.push(atoi(elem.c_str()));
            }
        }
        cout << ret.top() << endl;
    }
    return 0;
}