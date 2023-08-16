class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        int ans = 0;
        sort(nums.begin(),nums.end());
        while(left<right){
            if(nums[left] + nums[right] == k){
                ans++;
                left++;
                right--;
            }
            else if(nums[left] + nums[right] > k){
                right--;
            }
            else{
                left++;
                
            }
        }
        
        return ans;
    }
};