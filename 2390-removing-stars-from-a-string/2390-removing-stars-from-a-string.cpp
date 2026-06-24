class Solution {
public:
    string removeStars(string s) {
        stack<int> st;
        for(char c:s){
            if(st.size()>0 && c=='*')
                st.pop();
            else if(c!='*')
                st.push(c);
        }
        string res="";
        while(!st.empty()){
            char c=st.top();
            st.pop();
            res+=c;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};