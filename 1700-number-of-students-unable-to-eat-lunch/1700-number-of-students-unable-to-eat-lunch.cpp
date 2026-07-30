class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
       stack<int>s;
       queue<int>q;
       int hungry=0;
       int temp;
       for(auto x:students){
        q.push(x);
       }
        for(int i=sandwiches.size()-1;i>=0;i--)
            s.push(sandwiches[i]);
        while(!q.empty()){
            if(q.front()==s.top()){
                q.pop();
                s.pop();
                hungry=0;
            }
            else{
                temp=q.front();
                q.pop();
                q.push(temp);
                hungry++;
            }
            if(hungry==q.size())
                break;
        }
        return hungry;
    }
};

