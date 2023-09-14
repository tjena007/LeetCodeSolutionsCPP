class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        helper(1,temp,ans,k,n);
        
        return ans;
    }
    
    void helper(int idx,vector<int>& temp,vector<vector<int>>& ans,int k,int target){
        if(temp.size() == k){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }
        
        for(int i=idx;i<=9;i++){
            if(i<=target){
                temp.push_back(i);
                helper(i+1,temp,ans,k,target-i);
                temp.pop_back();
            }
        }
    }
};