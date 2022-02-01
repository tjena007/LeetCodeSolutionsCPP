class Solution {
public:
    int maxProfit(vector<int>& prices) {
       stack<int> st;
       int ans=INT_MIN;
       vector<int> nums;
       for(int i= prices.size()-1;i>=0;i--){
           if(st.size() == 0){
               nums.push_back(0);
               st.push(prices[i]);
           }
           else if(st.top()<prices[i]){
               nums.push_back(0);
               st.push(prices[i]);
           }
           else if(st.top()>prices[i]){
               nums.push_back(st.top());
           }
           else if(st.top() == prices[i]){
               nums.push_back(0);
           }
       }
        
       
        reverse(nums.begin(),nums.end());
        
        for(int i=0;i<prices.size();i++){
            nums[i]-=prices[i];
        }
        
        for(auto i: nums){
            //cout << i<< endl;
            ans = max(ans,i);
        }
        if(ans<0){
            ans=0;
        }
        
       return ans;
    }
};