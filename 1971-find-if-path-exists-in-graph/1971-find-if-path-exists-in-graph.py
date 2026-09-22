class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        adj=[[] for i in range(n)]
        for i,j in edges:
            adj[i].append(j)
            adj[j].append(i)
        status=[0]*n
        q=[]
        q.append(source)
        status[source]=1
        while len(q)>0:
            x=q.pop(0)
            l=adj[x]
            for y in l:
                if status[y]==0:
                    status[y]=1
                    q.append(y)

        if status[destination]==0:
            return False
        return True

        