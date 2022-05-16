class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto i: nums){
            m[i]++;
        }
        
        priority_queue<pair<int,int>> maxh;
        
        for(auto i: m){
            maxh.push({i.second,i.first});
        }
        vector<int> ans;
        int i=1;
        while(i<=k){
            auto top = maxh.top();
            maxh.pop();
            ans.push_back(top.second);
            i++;
        }
        
        return ans;
    }
};