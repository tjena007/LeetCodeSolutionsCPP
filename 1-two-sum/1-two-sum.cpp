class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int,vector<int>> m;
        
        for(int i=0;i<nums.size();i++){
            m[nums[i]].push_back(i);
        }
        
        for(int i=0;i<nums.size();i++){
            int tosearch = target - nums[i];
            auto it = m.find(tosearch);
            if (it != m.end()){
                for(auto j : m[tosearch]){
                    if(j!= i){
                        vector<int> ans = {i,j};
                        return ans;
                    }
                }
            }
        }
        
        return {};
        
    }
};