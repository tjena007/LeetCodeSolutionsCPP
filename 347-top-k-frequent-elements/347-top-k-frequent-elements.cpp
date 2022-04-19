class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        
        for(auto i: nums){
            m[i]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minh;
        
        for(auto i : m){
            minh.push({i.second,i.first});
            if(minh.size()>k) minh.pop();
        }
        
        vector<int> ans;
        
        while(minh.size() != 0){
            auto t = minh.top();
            ans.push_back(t.second);
            minh.pop();
        }
        
        return ans;
    }
};