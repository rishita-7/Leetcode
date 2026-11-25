class Solution:
    def countBattleships(self, board: list[list[str]]) -> int:
        m = len(board)
        n = len(board[0])

        count = 0

        def isValid(i, j):
            return 0 <= i < m and 0 <= j < n

        directions = [(1,0), (0,1), (-1,0), (0,-1)]

        for i in range(m):
            for j in range(n):

                if board[i][j] == 'X':
                    stack = [(i,j)]
                    board[i][j] = 'v'
                    count += 1

                    while stack:
                        x, y = stack.pop()

                        for dx, dy in directions:
                            nx, ny = x + dx, y + dy

                            if isValid(nx, ny) and board[nx][ny] == 'X':
                                stack.append((nx,ny))
                                board[nx][ny] = 'v'

        return count
