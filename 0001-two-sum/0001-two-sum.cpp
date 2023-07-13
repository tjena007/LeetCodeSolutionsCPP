class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]] = i;
        }

        for(int i=0;i<nums.size();i++){
            int diff = target - nums[i];
            auto it = m.find(diff);
            //cout << it;
            if(it != m.end() && i!=m[diff]){
                return {i,m[diff]};
            }
        }

        return {};
    }
};