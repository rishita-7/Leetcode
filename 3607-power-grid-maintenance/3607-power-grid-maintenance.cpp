class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> adj(c + 1);
        for (auto &edge : connections) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> comp(c + 1, -1);
        int compId = 0;
        for (int i = 1; i <= c; i++) {
            if (comp[i] == -1) {
                queue<int> q;
                q.push(i);
                comp[i] = compId;
                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    for (int v : adj[u]) {
                        if (comp[v] == -1) {
                            comp[v] = compId;
                            q.push(v);
                        }
                    }
                }
                compId++;
            }
        }

        vector<set<int>> online(compId);
        vector<bool> isOnline(c + 1, true);
        for (int i = 1; i <= c; i++) {
            online[comp[i]].insert(i);
        }

        vector<int> result;
        for (auto &q : queries) {
            int type = q[0], x = q[1];
            int cid = comp[x];
            if (type == 1) {
                if (isOnline[x]) {
                    result.push_back(x);
                } else if (!online[cid].empty()) {
                    result.push_back(*online[cid].begin());
                } else {
                    result.push_back(-1);
                }
            } else {
                if (isOnline[x]) {
                    isOnline[x] = false;
                    online[cid].erase(x);
                }
            }
        }
        return result;    
    }
};