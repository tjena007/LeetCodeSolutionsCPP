class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) break;
            int target = 0 - nums[i];
            int low = i+1,high = nums.size()-1;
            while(low < high){
                if(nums[low]+nums[high] == target){
                    ans.push_back({nums[i],nums[low],nums[high]});
                    
                    while((low < high) && nums[low+1] == nums[low])low++;
                    low++;
                    while((low < high) && nums[high-1] == nums[high])high--;
                    high--;
                }
                else if(nums[low]+nums[high] > target) high--;
                else low++;
            }
        }
        
        sort(ans.begin(),ans.end());
        
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
        return ans;
    }
};