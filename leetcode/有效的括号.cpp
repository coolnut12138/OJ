class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '{' || s[i] == '[' || s[i] == '('){
                st.push(s[i]);
            }
            else{
                switch(s[i]){
                    case '}':
                    case ']':
                    case ')':
                        if(st.empty()){
                            return false;
                        }
                        char left = st.top();
                        st.pop();
                        if(!((left == '{' && s[i] == '}')
                          || (left == '[' && s[i] == ']')
                          ||(left == '(' && s[i] == ')'))){
                            return false;
                        }
                        break;
                }
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};