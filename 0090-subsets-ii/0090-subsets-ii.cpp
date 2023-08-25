class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        sort(nums.begin(),nums.end());
        vector<int> temp;
        
        calc(0,temp,nums,st);
        
        vector<vector<int>> ans;
        for(auto i : st){
            ans.push_back(i);
        }
        
        return ans;
    }
    
    void calc(int idx,vector<int>& temp,vector<int>& nums, set<vector<int>>& st){
        if(idx == nums.size()){
            st.insert(temp);
            return;
        }
        
        temp.push_back(nums[idx]);
        calc(idx+1,temp,nums,st);
        temp.pop_back();
        calc(idx+1,temp,nums,st);
    }
};