class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int,int> m;
        vector<int> ans;
        for(int i=0;i<numbers.size();i++){
            m[numbers[i]] = i;
        }
        
        for(int i=0;i<numbers.size();i++){
            int tofind = target -numbers[i];
            
            if(m[tofind] && i!= m[tofind]){
                ans.push_back(i+1);
                ans.push_back(m[tofind]+1);
                break;
            }
        }
        
        return ans;
    }
};