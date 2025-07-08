class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        q = deque()
        ROWS,COLS = len(board),len(board[0])

        for i in range(ROWS):
            if board[i][0] == 'O':
                q.append((i,0))
                
            if board[i][COLS-1] == 'O':
                q.append((i,COLS-1))
        
        for j in range(COLS):
            if board[0][j] == 'O':
                q.append((0,j))
                
            if board[ROWS-1][j] == 'O':
                q.append((ROWS-1,j))
        

        #bfs
        while q:
            for i in range(len(q)):
                row,col = q.popleft()
                board[row][col] = 'T'
                directions = [(0,1),(-1,0),(0,-1),(1,0)]

                for di,dj in directions:
                    if 0 <= row+di < ROWS and 0 <= col+dj < COLS and board[row+di][col+dj] == 'O':
                        q.append((row+di,col+dj))
        
        for i in range(ROWS):
            for j in range(COLS):
                if board[i][j] == 'T':
                    board[i][j] = 'O'
                elif board[i][j] == 'O':
                    board[i][j] = 'X'
