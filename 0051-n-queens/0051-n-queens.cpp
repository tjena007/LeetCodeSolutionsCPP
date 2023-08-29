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
        
        //row array
        vector<int> rowCheck(n,0);
        //upper diag arr
        vector<int> ulCheck(2*n - 1,0);
        //lower diag arr
        vector<int> blCheck(2*n - 1,0);
        
        solve(0,n,temp,ans,rowCheck,ulCheck,blCheck);
        
        return ans;
    }
    
    void solve(int col,int n,vector<string>& temp, vector<vector<string>>& ans,vector<int>& rowCheck,vector<int>& ulCheck,vector<int>& blCheck){
        if(col == n){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(rowCheck[i] == 0 && blCheck[i + col] == 0 && ulCheck[n-1 + col - i] == 0){
                temp[i][col] = 'Q';
                rowCheck[i] = 1;
                blCheck[i + col] = 1;
                ulCheck[n-1 + col -i] = 1;
                
                solve(col+1,n,temp,ans,rowCheck,ulCheck,blCheck);
                temp[i][col] = '.';
                rowCheck[i] = 0;
                blCheck[i + col] = 0;
                ulCheck[n-1 + col -i] = 0;
            }
        }
    }
    
    
};