class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        // set<vector<int>> st;
        sort(candidates.begin(),candidates.end());
        helper(temp,0,ans,candidates,target);
        
        return ans;
    }
    
    void helper(vector<int>& temp,int index,vector<vector<int>>& ans,vector<int>& candidates,int target){
        if(index == candidates.size()){
            if(target == 0){
                ans.push_back(temp);
            }   
            return;
        }
        
        
        if(candidates[index] <= target){
            temp.push_back(candidates[index]);
            helper(temp,index,ans,candidates,target-candidates[index]);
            temp.pop_back();
        }
        helper(temp,index+1,ans,candidates,target);
        
    }
};