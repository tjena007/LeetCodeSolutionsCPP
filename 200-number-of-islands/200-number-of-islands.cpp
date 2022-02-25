class Solution {
public:
    void helper(vector<vector<char>>& grid,int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[i].size() || grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '0';
        //left
        helper(grid,i,j-1);
        //top
        helper(grid,i-1,j);
        //right
        helper(grid,i,j+1);
        //bottom
        helper(grid,i+1,j);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == '1'){
                    ans++;
                    //grid[i][j] == '0';
                    helper(grid,i,j);
                }
            }
        }
        
        return ans;
    }
};