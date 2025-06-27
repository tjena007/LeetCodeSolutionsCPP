class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m = len(grid)
        n = len(grid[0])
        def dfs(row,col):
            grid[row][col] = True #visited


            directions = [(0,1),(-1,0),(0,-1),(1,0)]

            for di,dj in directions:
                nrow = row + di
                ncol = col + dj

                if nrow >= 0 and nrow < m and ncol >= 0 and ncol < n and grid[nrow][ncol] == '1':
                    dfs(nrow,ncol)

        
        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    dfs(i,j)
                    ans += 1
        
        return ans

