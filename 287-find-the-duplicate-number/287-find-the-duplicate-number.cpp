class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            if(ans == nums[i]) return ans;
            else{
                ans = nums[i];
            }
        }
        
        return ans;
    }
};