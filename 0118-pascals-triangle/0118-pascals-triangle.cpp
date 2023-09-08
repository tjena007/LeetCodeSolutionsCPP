class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        create(ans,numRows);
        
        return ans;
    }
    
    vector<int> create(vector<vector<int>>& ans,int numRows){
        if(numRows == 1){
            ans.push_back({1});
            return {1};
        }
        
        vector<int> prev = create(ans,numRows - 1);
        
        vector<int> curr(numRows);
        curr[0] = 1; 
        curr[numRows-1] = 1;
        for(int i=1;i<numRows-1;i++){
            curr[i] = prev[i-1] + prev[i];
        }
        
        ans.push_back(curr);
        return curr;
    }
};