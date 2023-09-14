class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        helper(0,temp,candidates,ans,target);
        
        return ans;
    }
    
    void helper(int idx, vector<int>& temp,vector<int>& candidates,vector<vector<int>>& ans,int target){
        
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        
        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            
            temp.push_back(candidates[i]);
            helper(i+1,temp,candidates,ans,target-candidates[i]);
            temp.pop_back();
        }
    }
};