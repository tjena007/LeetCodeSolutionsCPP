class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> temp;
        
        calc(0,temp,nums,ans);
        
        return ans;
    }
    
    void calc(int idx,vector<int>& temp,vector<int>& nums, vector<vector<int>>& ans){
        ans.push_back(temp);
        if(idx == nums.size()){
            return;
        }
        
        for(int i = idx;i<nums.size();i++){
            if(i>idx && nums[i] == nums[i-1]) continue;
            
            temp.push_back(nums[i]);
            calc(i+1,temp,nums,ans);
            temp.pop_back();   
        }
    }
};