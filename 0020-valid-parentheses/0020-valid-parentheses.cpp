class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for (char c:s){
            if (c=='{' || c=='[' || c=='(')
                st.push(c);
            else if(st.empty())
                return false;
            else{
                int t=st.top();
                if((t=='{' && c=='}')
                || (t=='[' && c==']')
                || (t=='(' && c==')'))
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};
