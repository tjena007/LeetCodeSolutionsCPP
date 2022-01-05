class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,int> m;
        bool ans=true;
        
        for(auto i : s){
            m[i]++;
        }
        
        for(auto i: t){
            if(m[i] == 0){
                return false;
            }
            else{
                m[i]--;
            }
        }
        
        return ans;
    }
};