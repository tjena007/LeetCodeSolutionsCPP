class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftProd(n,0);
        vector<int> rightProd(n,0);
         vector<int> ans(n,0);
        
        //find left prod
        leftProd[0] = 1;
        for(int i=1;i<n;i++){
            leftProd[i] = leftProd[i-1] * nums[i-1];
        }

        //find right prod
        rightProd[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            rightProd[i] = rightProd[i+1] * nums[i+1];
        }

        for(int i=0;i<n;i++){
            ans[i] = leftProd[i] * rightProd[i];
        }

        return ans;
    }
};