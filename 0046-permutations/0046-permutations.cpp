class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        calc(0,nums, ans);
        
        return ans;
    }
    
    void calc(int idx,vector<int>& nums,vector<vector<int>>& ans){
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            calc(idx+1,nums, ans);
            swap(nums[i],nums[idx]);
        }
    }
};