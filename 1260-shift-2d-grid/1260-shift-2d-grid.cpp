class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        for(int i=1;i<=k;i++){
            int m = grid.size();
            int n = grid[0].size();
            int num = grid[m-1][n-1];
            for(int j=m-1;j>=0;j--){
                for(int k=n-1;k>=0;k--){                    
                    if(k-1 < 0){
                        if(j-1 >= 0){
                            grid[j][k] =grid[j-1][n-1];       
                        }
                        else{
                            grid[j][k] = num;
                        }  
                    }
                    else{
                        grid[j][k] =grid[j][k-1];   
                    }
                }
            }
        }
        
        return grid;
    }
};