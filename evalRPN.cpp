//leetcode150.�沨�����ʽ��ֵ
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		//˼·�����������ѹջ���������������ȡ��ջ�����ݽ������㣬
		//������ѹջ�����´μ���ʹ��
		stack<int> st;
		int sz = tokens.size();
		for (int i = 0; i < sz; i++){
			string& num = tokens[i];
			//string�ĳ�Ա��string��Ҫ��""��������������''
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