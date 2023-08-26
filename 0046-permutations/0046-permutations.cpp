class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        map<int,int> m;
        vector<int> temp;
        vector<vector<int>> ans;
        
        calc(nums, temp, m, ans);
        
        return ans;
    }
    
    void calc(vector<int>& nums,vector<int>& temp,map<int,int>& m,vector<vector<int>>& ans){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]] == 0){
                m[nums[i]] = 1;
                temp.push_back(nums[i]);
                calc(nums, temp, m, ans);
                temp.pop_back();
                m[nums[i]] = 0;
            }
        }
    }
};