class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        map<int,bool> mrow;
        map<int,bool> mcol;
        
        int m = matrix.size(),n=matrix[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0 && !vis[i][j]){
                    if(mrow[i] == false){
                        for(int k=0;k<n;k++){
                            if(matrix[i][k] != 0){
                                matrix[i][k] = 0;
                                vis[i][k] = true;
                            } 
                        }
                        mrow[i] = true;
                    }
                    
                    if(mcol[j] == false){
                        for(int k=0;k<m;k++){
                            if(matrix[k][j] != 0){
                                matrix[k][j] = 0;
                                vis[k][j] = true;
                            }
                        }
                        mcol[j] = true;
                    }
                    vis[i][j] = true;
                }
            }
        }

    }
};