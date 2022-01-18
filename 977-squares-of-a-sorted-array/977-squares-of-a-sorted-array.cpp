class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       vector<int> ans(nums.size());       
       int low=0,high = nums.size()-1;
        int index = nums.size()-1;
        while(low<=high){
            if(abs(nums[low]) >= abs(nums[high])){
                ans[index] = nums[low];
                index--;
                low++;
            }
            else{
                ans[index] = nums[high];
                index--;
                high--;
            }
        }
        
        // for(auto i : ans){
        //     cout << i << " ";
        // }
        
        for(int i=0;i<ans.size();i++){
            ans[i]*=ans[i];
        }
        
        return ans;
        
    }
};