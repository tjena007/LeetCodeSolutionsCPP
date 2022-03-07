class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int> left,vector<int> right){
        if(right.size() == 0){
            if(left.size()>=2){
                ans.push_back(left);
            }
            return;
        }
        if(right[0]>=left[left.size()-1]){
            //yes
            vector<int> l = left;
            l.push_back(right[0]);
            vector<int> r = right;
            r.erase(r.begin()+0);
            helper(l,r);
            //no
            helper(left,r);
        }
        else{
            vector<int> r = right;
            r.erase(r.begin()+0);
            helper(left,r);
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            vector<int> left = {nums[i]};
            vector<int> right = {nums.begin()+i+1,nums.end()};
            helper(left,right);
        }
        
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
        return ans;
    }
};