class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //take element or not take
        // move the pointer to next element
        vector<vector<int>> ans;
        int idx = 0;
        vector<int> temp;
        set<vector<int>> st;
        
        helper(idx,nums,st,temp);
        
        for(auto it : st){
            ans.push_back(it);
        }
        
        return ans;
    }
    
    void helper(int idx,vector<int>& nums,set<vector<int>>& st,vector<int>& temp){
        if(idx == nums.size()){
            st.insert(temp);
        }
        
        for(int i=idx;i<nums.size();i++){
            temp.push_back(nums[i]);
            helper(i+1,nums,st,temp);
            temp.pop_back(); //removes the inserted element
            helper(i+1,nums,st,temp);
        }
    }
};