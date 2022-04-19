class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> m;
        
        for(auto i : nums){
            if(m[i]>0){
                return true;
            }
            else{
                m[i]++;
            }
        }
        
        return false;
    }
};