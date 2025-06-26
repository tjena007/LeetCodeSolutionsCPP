class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        ans = []

        mat = [['.'] * n for _ in range(n)]
        
        def check(row,col):
            #row check
            for i in range(0,col):
                if mat[row][i] == 'Q':
                    return False
                
            #top left diagonal check
            i,j = row - 1, col - 1
            while i >= 0 and j >= 0:
                if mat[i][j] == 'Q':
                    return False
                
                i -= 1
                j -= 1
            
            #bottom left diagonal check
            i,j = row + 1, col - 1
            while i < n and j >= 0:
                if mat[i][j] == 'Q':
                    return False
                
                i += 1
                j -= 1
            
            return True

        def dfs(col):
            if col == n:
                board = [''.join(row) for row in mat]
                ans.append(board)
                return
            
            for i in range(n):
                if check(i,col):
                    mat[i][col] = 'Q'
                    dfs(col+1)
                    mat[i][col] = '.' #backtrack
        

        dfs(0)
        return ans
