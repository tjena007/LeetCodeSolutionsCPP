class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        stack<int> st;
        for(auto i : nums){
            if (i == 0){
                st.push(i);
            }
        }
        
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]!=0){
                st.push(nums[i]);
            }
        }
        
        
        for(int i=0;i<nums.size();i++){
            nums[i] = st.top();
            st.pop();
        }
        
        return;
        
    }
};