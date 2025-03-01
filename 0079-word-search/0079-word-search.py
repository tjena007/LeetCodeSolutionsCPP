class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])
        
        def dfs(i, j, wordIdx):
            if wordIdx == len(word):  # Base case: full word matched
                return True

            # Direction vectors for right, down, left, up
            directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

            temp = board[i][j]
            board[i][j] = '#'  # Mark as visited
            
            for di, dj in directions:
                ni, nj = i + di, j + dj
                if 0 <= ni < m and 0 <= nj < n and board[ni][nj] == word[wordIdx]:
                    if dfs(ni, nj, wordIdx + 1):  # Recursively check next character
                        return True
            
            board[i][j] = temp  # Backtrack (undo visit)
            return False
        
        for i in range(m):
            for j in range(n):
                if board[i][j] == word[0]:  # Start DFS if first letter matches
                    if dfs(i, j, 1):
                        return True
        
        return False