class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> se;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            //if(nums[i]>0) break;
            int sum = 0 - nums[i];
            int low=0,high = nums.size() -1;
            while(low<high){
                if(nums[low]+nums[high] == sum && (low!=i && high != i)){
                    vector<int> s = {nums[low],nums[high],nums[i]};
                    sort(s.begin(),s.end());
                    // se.insert(s);
                    ans.push_back(s);
                    
                    while (low<high && nums[low] == nums[low+1]){
                        low++; 
                    } 
                    // to handle duplicates
                    while (low<high && nums[high] == nums[high-1]) {
                        high--;
                    }
                        
                    low++;
                    high--;
                }
                else if(nums[low]+nums[high] > sum){
                    high--;
                }
                else{
                    low++;
                }
            }
        }
        
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
        return ans;
        
    }
};