class Solution:
    def shortestBridge(self, grid):
        m, n = len(grid), len(grid[0])
        q = deque()
        dirs = [(-1,0),(1,0),(0,-1),(0,1)]
        
        # Step 1: BFS to find and mark the first island
        def bfs_mark(i, j):
            island = deque()
            island.append((i,j))
            grid[i][j] = -1  # mark visited
            
            while island:
                x, y = island.popleft()
                q.append((x,y))  # add to global queue for expansion
                for dx, dy in dirs:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] == 1:
                        grid[nx][ny] = -1
                        island.append((nx,ny))
        
        found = False
        for i in range(m):
            if found: break
            for j in range(n):
                if grid[i][j] == 1:
                    bfs_mark(i, j)
                    found = True
                    break
        
        # Step 2: BFS expansion to reach the second island
        steps = 0
        while q:
            for _ in range(len(q)):
                x, y = q.popleft()
                for dx, dy in dirs:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < m and 0 <= ny < n:
                        if grid[nx][ny] == 1:
                            return steps  # reached second island
                        if grid[nx][ny] == 0:
                            grid[nx][ny] = -1
                            q.append((nx,ny))
            steps += 1
        
        return -1
