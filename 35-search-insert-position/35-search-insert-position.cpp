class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = -1;
        
        int low=0,high = nums.size()-1;
        
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid]>target){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        //cout << low << " " << high;
        index=low;
        return index;
    }
};