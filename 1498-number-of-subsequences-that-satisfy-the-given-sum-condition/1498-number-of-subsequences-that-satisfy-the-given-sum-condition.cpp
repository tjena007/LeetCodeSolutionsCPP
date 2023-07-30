class Solution {
public:
   
    int numSubseq(vector<int>& nums, int target) {
        int mod=1e9+7;
        int ans=0;
        int n=nums.size();
        int left=0,right=n-1;
        sort(nums.begin(),nums.end());
        vector<int> pow(n,1);
        for(int i=1;i<n;i++)
        {
            pow[i]=pow[i-1]*2%mod;
        }
        while(left<=right)
        {
            if((nums[left]+nums[right])>target)
            {
                right-=1;
            }
            else
            {
                ans=(ans+(pow[right-left]%mod))%mod;
                left+=1;
            }
        }
        return ans%mod;
    }
};