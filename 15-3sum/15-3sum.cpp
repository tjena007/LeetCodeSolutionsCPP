class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        map<vector<int>,int> m;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)break;
            
            int target = 0 - nums[i];
            
            int low=0,high=nums.size()-1;
            
            while(low<high){
                if(nums[low]+nums[high] == target){
                    if(low == i){
                        low++;
                    }
                    else if( high ==i){
                        high--;
                    }
                    else{
                        vector<int> temp = {nums[low],nums[high],nums[i]};
                        sort(temp.begin(),temp.end());
                        m[temp]++;
                        
                        while (low<high && nums[low] == nums[low+1]){
                        low++; 
                        } 
                        // to handle duplicates
                        while (low<high && nums[high] == nums[high-1]) {
                            high--;
                        }
                        
                        high--;
                        low++;
                    }
                }
                else if(nums[low]+nums[high] > target){
                    high--;
                }
                else{
                    low++;
                }
            }
        }
        vector<vector<int>> ans;
        for(auto i: m){
            ans.push_back(i.first);
        }
        
        return ans;
        
    }
};