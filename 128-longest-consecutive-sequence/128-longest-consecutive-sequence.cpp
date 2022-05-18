class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        map<int,int> m;
        for(auto i: nums){
            m[i]++;
        }
        int ans=0;
        int cc = 1;
        int curr = INT_MIN;
        for(auto i : m){
            if(i.first == curr + 1){
                cc++;
                curr = i.first;
            }
            else{
                ans = max(ans,cc);
                curr = i.first;
                cc = 1;
            }
        }
        ans = max(ans,cc);
        
        return ans;
    }
};