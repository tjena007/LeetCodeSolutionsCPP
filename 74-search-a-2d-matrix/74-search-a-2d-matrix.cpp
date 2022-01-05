class Solution {
public:
    bool search(vector<int> m,int target){
        int low=0,high=m.size()-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(target == m[mid]){
                return true;
            }
            else if(target > m[mid]){
                low =mid+1;
            }
            else{
                high = mid -1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //bool ans = false;
        int rowl=0;
        int rowh=matrix.size() -1;
        
        int j = matrix[0].size()-1;
        for(int i=0;i<matrix.size();i++){
            
            if(target>=matrix[i][0] && target <= matrix[i][j]){
                return search(matrix[i],target);
            }
        }
        
        return false;
    }
};