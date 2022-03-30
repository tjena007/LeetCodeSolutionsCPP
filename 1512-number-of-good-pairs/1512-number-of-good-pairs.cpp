class Solution {
public:
    
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int> m;
        int sum = 0;
        for(auto i: nums){
            m[i]++;
        }
        
        for(auto i: m){
            if(i.second > 1){
                sum+= ((i.second)*(i.second -1))/2;
            }
        }
        
        return sum;
    }
};