class Solution {
public:
   
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int maxrow = matrix.size()-1,maxcol=matrix[0].size()-1;
        int minrow= 0,mincol =0;
        vector<vector<bool>> vis(maxrow+1,vector<bool>(maxcol+1,false));
        
        while(minrow <= maxrow && mincol<=maxcol){
            //upp row
            for(int i=mincol;i<=maxcol;i++){
                if(!vis[minrow][i]){
                    ans.push_back(matrix[minrow][i]);   
                    vis[minrow][i] = true;
                }
            }
            minrow++;
            
            //max col
            for(int i=minrow;i<=maxrow;i++){
                if(!vis[i][maxcol]){
                    ans.push_back(matrix[i][maxcol]);
                    vis[i][maxcol] = true;
                }
            }
            maxcol--;
            
            //maxrow
            for(int i=maxcol;i>=mincol;i--){
                if(!vis[maxrow][i]){
                    ans.push_back(matrix[maxrow][i]);
                    vis[maxrow][i] = true;
                }
                
            }
            maxrow--;
            
            //mincol
            for(int i=maxrow;i>=minrow;i--){
                if(!vis[i][mincol]){
                    ans.push_back(matrix[i][mincol]);
                    vis[i][mincol] = true;
                }
                
            }
            mincol++;
        }
        
        return ans;
    }
};