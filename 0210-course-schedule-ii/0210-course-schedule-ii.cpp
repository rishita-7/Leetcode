class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);
        vector<int>order;
        for(auto p: prerequisites){ 
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
        for (int i=0;i<indegree.size();i++){
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            order.push_back(node);
            for(int neigh:adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0)
                    q.push(neigh);
            }
        }
        if(order.size()==numCourses)
            return order;
        return {};
    }
};