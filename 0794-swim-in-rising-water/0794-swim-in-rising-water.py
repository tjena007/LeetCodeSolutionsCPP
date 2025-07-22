class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        visited = set()
        minHeap = [[grid[0][0],0,0]] #for djisktra
        N = len(grid)
        directions = [[0,1],[-1,0],[0,-1],[1,0]]

        visited.add((0,0))

        while minHeap:
            t,r,c = heapq.heappop(minHeap)

            if r == N-1 and c == N-1:
                return t
            
            for di,dj in directions:
                nr = r + di
                nc = c + dj
                if 0 <= nr < N and 0 <= nc < N and (nr,nc) not in visited:
                    visited.add((nr,nc))
                    heapq.heappush(minHeap,[max(t,grid[nr][nc]),nr,nc])
        

