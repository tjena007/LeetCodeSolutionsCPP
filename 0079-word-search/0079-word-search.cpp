class Solution {
public:
    bool dfs(vector<vector<char>>& board, int row, int col,string& word,int index,vector<vector<bool>>& vis){
        if(index == word.size()-1){
            // cout << board[row][col] << " here" << endl;
            if(board[row][col] == word[index]) return true;
            return false;
        }
        
        int delrow[] = {+1,0,-1,0};
        int delcol[] = {0,+1,0,-1};

        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow<board.size() && ncol>=0 && ncol<board[0].size() 
&& board[nrow][ncol] == word[index+1] && vis[nrow][ncol] == false){
                vis[nrow][ncol] = true;
                // cout <<board[row][col] << "  " << nrow << " " << ncol << endl;
                if(dfs(board,nrow,ncol,word,index+1,vis)==true) return true;
                vis[nrow][ncol] = false;
            }
        }
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == word[0]){
                    vector<vector<bool>> vis(m,vector<bool>(n,false));
                    vis[i][j] = true;
                    if(dfs(board,i,j,word,0,vis) == true) return true;
                }
                
            }
        }
        
        return false;
    }
};