class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        q = deque()
        #use bfs to put all rotten oranges into queue
        # check count of fresh oranges as well, if 0 return 0, if not rotten oranges return -1
        # start time, at end of every while loop iteration, increase time by 1
        # after q is empty, check if there are any fresh oranges, if yes return -1
        m,n = len(grid), len(grid[0])
        freshOrange = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    q.append((i,j))
                elif grid[i][j] == 1:
                    freshOrange += 1
        
        if freshOrange == 0:
            return 0
        
        if len(q) == 0:
            return -1
        
        #bfs
        ans = 0
        while q:
            for i in range(len(q)):
                row,col = q.popleft()
                # print(row,col)

                directions = [(0,1),(-1,0),(0,-1),(1,0)]

                for di,dj in directions:
                    ni = row + di
                    nj = col + dj

                    if 0 <= ni < m and 0 <= nj < n and grid[ni][nj] == 1:
                        grid[ni][nj] = 2
                        q.append((ni,nj))
            
            ans += 1

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    return -1
        
        return ans - 1
            
