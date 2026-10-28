class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char,int>, vector<pair<char,int>>, greater<pair<char,int>>> pq;
        for (int i=0;i<s.size();i++){
            if(s[i]=='*'){
                if(!pq.empty())
                    pq.pop();
            }
            else{
                pq.push({s[i],-i});
            }
        }
        vector<pair<char,int>> res;
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        sort(res.begin(),res.end(), [](const auto &a, const auto &b){
            return -a.second<-b.second;
        });
        string result="";
        for(auto a:res){
            result+=a.first;
        }
        return result;
    }
};