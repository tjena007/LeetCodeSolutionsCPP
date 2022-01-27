class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        map<char,int> m1;
        map<char,int> m2;
        
        for(auto i: s){
            m1[i]++;
        }
        
        for(auto i: t){
            m2[i]++;
        }
        
        for(auto i: m1){
            if(i.second != m2[i.first]){
                return false;
            }
        }
        
        return true;
    }
};