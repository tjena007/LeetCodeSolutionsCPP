class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        ROWS,COLS = len(heights),len(heights[0])
        pacific,atlantic = set(),set()

        def dfs(row,col,visited,prevHeight):
            if((row,col) in visited or row < 0 or col < 0 or row == ROWS or col == COLS or heights[row][col] < prevHeight):
                return 
            
            visited.add((row,col))

            directions = [(0,1),(-1,0),(0,-1),(1,0)]

            for di,dj in directions:
                dfs(row+di,col+dj,visited,heights[row][col])

        # top row and bottom to check from pacific and atlantic 
        for c in range(COLS):
            dfs(0,c,pacific,heights[0][c])
            dfs(ROWS-1,c,atlantic,heights[ROWS-1][c])


        # left col and right col to check from pacific and atlantic 
        for r in range(ROWS):
            dfs(r,0,pacific,heights[r][0])
            dfs(r,COLS-1,atlantic,heights[r][COLS - 1])


        ans = []
        # traverse graph if both atlantic and pacific add to answer
        for i in range(ROWS):
            for j in range(COLS):
                if (i,j) in pacific and (i,j) in atlantic:
                    ans.append([i,j])
        
        return ans
