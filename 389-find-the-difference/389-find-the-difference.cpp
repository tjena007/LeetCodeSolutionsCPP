class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> m1;
        
        for(auto i: t){
            m1[i]++;
        }
        
        for(auto i: s){
            m1[i]--;
        }
        
        for(auto i: m1){
            if(i.second>0){
                return i.first;
            }
        }
        
        return NULL;
    }
};