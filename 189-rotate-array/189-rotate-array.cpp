class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k==0 || k%nums.size()==0){
            return;
        }
        else{
            vector<int> temp1;
            for(int i=nums.size()-(k%nums.size());i<nums.size();i++){
                temp1.push_back(nums[i]);
            }
            // for(auto i : temp1){
            //     cout << i << endl;
            // }
            
            for(int i=nums.size()-(k%nums.size())-1;i>=0;i--){
                nums[i+(k%nums.size())] = nums[i];
            }
            
            for(int i=0;i<temp1.size();i++){
                nums[i] = temp1[i];
            }
            return;
        }
    }
};