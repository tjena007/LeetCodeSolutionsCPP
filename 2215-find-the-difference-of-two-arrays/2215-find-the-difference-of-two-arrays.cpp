class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        
        for(auto i : nums1){
            m1[i]++;
        }
        
        for(auto i : nums2){
            m2[i]++;
        }
        
        set<int> count1;
        set<int> count2;
        
        for(auto i : nums1){
            if(m2[i]==0){
                count1.insert(i);
            }
        }
        
        for(auto i : nums2){
            if(m1[i]==0){
                count2.insert(i);
            }
        }
        
        vector<int> t1;
        vector<int> t2;
        for(auto i : count1){
            t1.push_back(i);
        }
        
        for(auto i : count2){
            t2.push_back(i);
        }
        
        ans.push_back(t1);
        ans.push_back(t2);
        
        return ans;
    }
};