class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    bool solve(vector<vector<char>>& board){
        //iterate all elements to find emppty elements
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    for(char k='1';k<='9';k++){
                        if(isValid(board,i,j,k)){
                            board[i][j] = k;
                            
                            if(solve(board)) return true;
                            else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;   
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>& board,int row, int col, int val){
        for(int i=0;i<9;i++){
            if(board[i][col] == val) return false;
            
            if(board[row][i] == val) return false;
            
            //check 3x3 box
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val) return false;
        }
        
        return true;
    }
};