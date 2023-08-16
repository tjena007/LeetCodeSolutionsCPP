class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0,right = 1;
        while(right < nums.size()){
            // cout << left << " " << right << endl;
            if(left == right){
                right++;
            }
            else if(nums[left] != 0){
                left++;
            }
            else if(nums[left] == 0){
                if(nums[right] == 0) right++;
                else{
                    swap(nums[left],nums[right]);
                    left++;
                    right++;
                }
            }
        }
    }
};