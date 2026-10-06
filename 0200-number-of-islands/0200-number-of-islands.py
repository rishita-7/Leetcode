class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m=len(grid)
        n=len(grid[0])
        count=0
        s=set()
        for i in range(m):
            for j in range(n):
                if grid[i][j]== '1':
                    s.add((i,j))
        for x_i in range(m):
            for y_j in range(n):
                if(x_i,y_j) in s:
                    q=[(x_i,y_j)]
                    count+=1
                    s.remove((x_i,y_j))
                    while(q):
                        x,y=q.pop(0)
                        for i,j in [(0,1),(0,-1),(1,0),(-1,0)]:
                            if (x+i,y+j) in s:
                                s.remove((x+i,y+j))
                                q.append((x+i,y+j))
        return count
