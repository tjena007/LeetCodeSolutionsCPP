class Solution {
public:
    bool judgeSquareSum(int c) {
        vector<long> nums;
        float n = ceil(sqrt(c));
        for(int i=0;i<=n;i++){
            nums.push_back(i);
        }
        
        int i=0,j=nums.size()-1;
        long k = c;
        while(i<=j){
            long product = nums[i]*nums[i] + nums[j]*nums[j];
            if(product == k){
                return true;
            }
            else if(product > k){
                j--;
            }
            else{
                i++;
            }  
        }
        
        return false;
    }
};