class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        
        map<int,int> m;
        
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=i;
        }
        
        // for(auto i:m){
        //     cout << i.first << " " << i.second << endl;
        // }
        
        for(int i=0;i<nums.size();i++){
            int toSearch = target-nums[i];
            if ( m.find(toSearch) != m.end() && m[toSearch] != i ) {
                ans.push_back(i);
                ans.push_back(m[toSearch]);
                break;
            } 
        }
        
        
        
        return ans;
    }
};