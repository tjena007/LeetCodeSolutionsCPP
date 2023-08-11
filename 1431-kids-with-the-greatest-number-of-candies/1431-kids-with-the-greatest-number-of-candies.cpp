class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int len = candies.size();
        int maxCandies = INT_MIN;
        for(auto i: candies){
            maxCandies = max(maxCandies,i);
        }
        
        vector<bool> ans(len,false);
        
        for(int i=0;i<len;i++){
            if(candies[i]+extraCandies>=maxCandies){
                ans[i] = true;
            }
        }
        
        return ans;
    }
};