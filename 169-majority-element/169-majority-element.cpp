class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        
        for(auto i: nums){
            m[i]++;
        }
        int n = nums.size()/2;
        int ans = -1;
        
        for(auto i : m){
            if(i.second > n){
                ans = i.first;
                break;
            }
        }
        
        return ans;
    }
};