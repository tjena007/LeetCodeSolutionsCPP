class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> m;
        for(auto i:s1){
            m[i]++;
        }
        
        int i=0,j=0;
        
        int k = s1.size();
        int count = m.size();
        while(j<s2.size()){
            // auto it = m.find(s2[j]);
            if(m.count(s2[j]) == 1){
                m[s2[j]]--;
                if(m[s2[j]] == 0)count--;
            }
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                if(count == 0) return true;
                
                // auto it = m.find(s2[i]);
                if(m.count(s2[i]) == 1){
                    m[s2[i]]++;
                    if(m[s2[i]] == 1) count++;
                }
                i++;
                j++;
            }
            
        }
        return false;
    }
};