class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        unordered_map<int,int> left;
        unordered_map<int,int> right;
        unordered_map<int,vector<int>> ans;
        
        for(auto i: nums){
            right[i]++;
        }
        

        left[0] = 0;
        left[1] = 0;
        
        int maxn = INT_MIN;
        for(int i = 0; i< nums.size();i++){
            //cout << left[0] << " " <<right[1] <<endl;
            ans[left[0]+right[1]].push_back(i);
            maxn = max(maxn,left[0]+right[1]);
            right[nums[i]]--;
            left[nums[i]]++;
        }
        ans[left[0]+right[1]].push_back(nums.size());
        maxn = max(maxn,left[0]+right[1]);
        
        return ans[maxn];

    }
};