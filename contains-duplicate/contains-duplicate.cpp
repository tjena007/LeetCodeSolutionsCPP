class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> m;
        for(auto i: nums){
            m[i]+=1;
        }
        bool flag=false;
        for(auto i: m){
            if(i.second >1){
                flag=true;
                break;
            }
        }
        
        return flag;
    }
};