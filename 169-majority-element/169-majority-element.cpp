class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = nums[0],count =0;
        for(auto i : nums){
            if(i == maj) count++;
            else{
                count --;
                if(count == 0){
                    maj = i;
                    count++;
                }
            }
        }
        
        return maj;
    }
};