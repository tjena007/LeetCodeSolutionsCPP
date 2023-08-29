class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        //2 solutions
        //solution 1 : using backtracking
        // approach: go thru every column, for each column, check in all the rows if a queen can be placed there or not. Do this by checking if left rows, upper left diagonal and lower left diagonals have any queens or not , if not mark the cell with queen and go on
        // solution 2: optimised backtracking 
        // for rows, create array of n size, if queen placed mark that row true
        // for bottom left, create array of 2n - 1 size, mark the diagonal as arr[row + col] = true
        // for upper left, create array of 2n - 1 size, mark the diagonal as arr[n-1 + col - row] = true
        
         
        vector<vector<string>> ans;
        vector<string> temp(n,string(n,'.'));
        
        solve(0,n,temp,ans);
        
        return ans;
    }
    
    void solve(int col,int n,vector<string>& temp,vector<vector<string>>& ans){
        if(col == n){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(check(col,i,temp)){
                
                temp[i][col] = 'Q';
                solve(col+1,n,temp,ans);
                temp[i][col] = '.';
            }
        }
    }
    
    bool check(int col,int row,vector<string>& temp){
        //check row
        int r = row;
        int c = col;
        
        while(c>=0){
            if(temp[r][c] == 'Q') return false;
            c--;
        }
        c = col;
        
        //check upper left diag
        while(c>=0 && r>=0){
            if(temp[r][c] == 'Q') return false;
            c--;
            r--;
        }
        
        r = row;
        c = col;
        
        //check lower left diag
        while(c>=0 && r<temp.size()){
            if(temp[r][c] == 'Q') return false;
            c--;
            r++;
        }
        
        return true;
        
    }
};