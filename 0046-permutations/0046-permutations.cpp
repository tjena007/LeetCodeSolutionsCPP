class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        //keep element in the first position
        //move the index to find all combinations with num in that place
        //when idx reaches the end, add nums to ans
        //swap them back to keep nums in its original place
        
        helper(0,ans,nums); //to handle the backtracking
        
        return ans;
    }
    
    void helper(int idx,vector<vector<int>>& ans,vector<int>& nums){
        if(idx == nums.size()){
            ans.push_back(nums);
        }
        
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            helper(idx+1,ans,nums);
            swap(nums[idx],nums[i]);
        }
    }
};