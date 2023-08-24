class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        
        vector<int> temp;
        calc(0,candidates,temp,target,ans);
        
        return ans;
    }
    
    void calc(int idx,vector<int>& candidates, vector<int>& temp, int target,vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            
            temp.push_back(candidates[i]);
            calc(i+1,candidates,temp,target - candidates[i],ans);
            temp.pop_back();
        }
    }
};