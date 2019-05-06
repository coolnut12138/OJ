//leetcode150.逆波兰表达式求值
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		//思路：如果是数字压栈，当遇到运算符，取出栈中数据进行运算，
		//运算结果压栈方便下次计算使用
		stack<int> st;
		int sz = tokens.size();
		for (int i = 0; i < sz; i++){
			string& num = tokens[i];
			//string的成员是string，要用""括起来，不能用''
			if (num != "+" && num != "-" && num != "*" && num != "/"){
				st.push(atoi(num.c_str()));
			}
			else{
				int right = st.top();
				st.pop();
				int left = st.top();
				st.pop();
				if (num == "+")
					st.push(left + right);
				if (num == "-")
					st.push(left - right);
				if (num == "*")
					st.push(left * right);
				if (num == "/")
					st.push(left / right);
			}
		}
		return st.top();
	}
};