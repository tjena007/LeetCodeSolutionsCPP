class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        d= {}

        # row
        for i in range(0,9):
            d.clear()
            for j in range(0,9):
                if board[i][j] != '.':
                    d[board[i][j]] = d.get(board[i][j],0) + 1
                    if d[board[i][j]] > 1:
                        print(i, j, sep=",here  ") 
                        return False
        
        # col
        for i in range(0,9):
            d.clear()
            for j in range(0,9):
                if board[j][i] != '.':
                    d[board[j][i]] = d.get(board[j][i],0) + 1
                    if d[board[j][i]] > 1:
                        print(i, j, sep=", ") 
                        return False
        
        # 3x3
        for box_row in range(0, 9, 3):
            for box_col in range(0, 9, 3):
                d.clear()
                for i in range(box_row, box_row + 3):
                    for j in range(box_col, box_col + 3):
                        if board[i][j] != '.':
                            d[board[i][j]] = d.get(board[i][j], 0) + 1
                            if d[board[i][j]] > 1:
                                print(i, j, sep=", box")
                                return False


        return True
                