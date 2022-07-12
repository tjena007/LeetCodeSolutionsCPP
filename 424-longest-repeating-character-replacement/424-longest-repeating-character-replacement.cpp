class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 1,i=0,j=0;
        map<char,int> m;
        
        while(j<s.size()){
            m[s[j]]++;
            int mc = 0;
            for(auto i : m){
                mc = max(mc,i.second);
            }
            int len = j-i+1;
            if(len - mc <= k){
                ans = max(ans,len);
            }
            else{
                int mc2 = -1;
                while(len - mc2 > k){
                    m[s[i]]--;
                    i++;
                    for(auto i : m){
                        mc2 = max(mc2,i.second);
                    }
                    len = j-i+1;
                }
            }
            j++;
        }
        
        return ans;
    }
};