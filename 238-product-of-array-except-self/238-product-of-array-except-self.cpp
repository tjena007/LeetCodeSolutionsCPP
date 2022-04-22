class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left,ans;
        vector<int> right(nums.begin(),nums.end());
        
        
        left.push_back(1);
        right[right.size() - 1] = 1;
        
        for(int i=1;i<nums.size();i++){
            left.push_back(left[i-1] * nums[i-1]);
        }
        
        for(int i=nums.size()-2;i>=0;i--){
            right[i] = right[i+1]*nums[i+1];
        }
        
        for(int i=0;i<nums.size();i++){
            ans.push_back(left[i] * right[i]);
        }
        
        return ans;
    }
};