class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        n = len(grid)
        q = deque()
        
        # Add all land cells to the queue
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    q.append((i, j))
        
        # If no land or no water, return -1
        if not q or len(q) == n * n:
            return -1
        
        directions = [(1,0), (-1,0), (0,1), (0,-1)]
        distance = -1
        
        # BFS
        while q:
            for _ in range(len(q)):
                x, y = q.popleft()
                for dx, dy in directions:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < n and 0 <= ny < n and grid[nx][ny] == 0:
                        grid[nx][ny] = 1
                        q.append((nx, ny))
            distance += 1
        
        return distance
