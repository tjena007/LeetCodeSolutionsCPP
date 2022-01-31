class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int ans = 0;
        unordered_map<char,int> m;
        while(j<s.size()){
            m[s[j]]++;
            if(m.size() == j-i+1){
                // ans = std::max(m.size(),ans);
                ans = m.size()> ans ? m.size() : ans;
                j++;
            }
            else if(m.size() < j-i+1){
                while(m.size() < j-i+1){
                    m[s[i]]--;
                    if(m[s[i]] == 0){
                        m.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        
        
        
        return ans;
        
        
    }
};