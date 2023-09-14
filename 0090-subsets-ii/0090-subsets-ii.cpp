class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        
        helper(0,temp,st,nums);
        
        for(auto i : st){
            ans.push_back(i);
        }
        
        return ans;
    }
    
    void helper(int idx,vector<int>& temp,set<vector<int>>& st,vector<int>& nums){
        if(idx == nums.size()){
            st.insert(temp);
            return;
        }
        
        temp.push_back(nums[idx]);
        helper(idx+1,temp,st,nums);
        temp.pop_back();
        helper(idx+1,temp,st,nums);
    }
};