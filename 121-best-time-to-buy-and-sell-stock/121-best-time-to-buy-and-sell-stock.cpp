class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1){
            return 0;
        }
        
        int left = 0;
        int right = 1;
        
        int mprofit = 0;
        
        while(right < prices.size()){
            if(prices[left] > prices[right]){
                left = right;
                right++;
            }else{
                mprofit = max(mprofit, prices[right] - prices[left]);
                right++;
            }
        }
        
        return mprofit;
    }
};