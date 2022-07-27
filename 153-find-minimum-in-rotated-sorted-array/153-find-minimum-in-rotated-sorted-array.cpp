class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int low=0,high = nums.size() - 1, N = nums.size();
        
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] < nums[(mid+ N-1)%N] && nums[mid]< nums[(mid+1)%N]){
                return nums[mid];
            }
            else if(nums[mid] >= nums[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        
        return -1;
    }
};