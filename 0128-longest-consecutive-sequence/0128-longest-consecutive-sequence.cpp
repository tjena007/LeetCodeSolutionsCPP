class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        int maxNums = INT_MIN;
        for(auto i : nums){
            m[i]++;
            maxNums = max(maxNums,i);
        }
        
        int ans = 0;
        
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i]-1)== m.end()){
                int count = 0;
                int curr = nums[i];
                while(curr<=maxNums && m.find(curr) != m.end()){
                    curr++;
                    count++;
                }
                ans = max(ans,count);
            }
        }
        
        
        return ans;
    }
};