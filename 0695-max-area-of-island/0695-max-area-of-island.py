class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        ans = 0
        m,n = len(grid),len(grid[0])

        def dfs(row,col):
            grid[row][col] = 0


            directions = [(0,1),(-1,0),(0,-1),(1,0)]

            area = 1

            for di,dj in directions:
                ni = row + di
                nj = col + dj

                if  0 <= ni < m and 0 <= nj < n and grid[ni][nj] == 1:
                    area += dfs(ni,nj)
            
            return area
        

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    ct = dfs(i,j)
                    ans = max(ct,ans)
        
        return ans