class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int curr=0;
        for(auto i: nums){
            curr+=i;
            ans = max(ans,curr);
            if(curr<0){
                curr=0;
            }
        }
        
        return ans;
    }
};