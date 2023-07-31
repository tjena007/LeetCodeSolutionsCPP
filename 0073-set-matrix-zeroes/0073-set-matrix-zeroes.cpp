class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> setRows; 
        unordered_set<int> setColumns; 
        
        int m = matrix.size(),n=matrix[0].size();
        //vector<vector<bool>> vis(m,vector<bool>(n,false));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    setRows.insert(i);
                    setColumns.insert(j);
                }
            }
        }
        
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(setRows.count(i) > 0 || setColumns.count(j) > 0){
                    matrix[i][j] = 0;
                }
            }
         }

    }
};