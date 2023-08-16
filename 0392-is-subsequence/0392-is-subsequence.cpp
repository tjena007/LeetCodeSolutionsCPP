class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0,j=0;
        while(j<t.size()){
            // cout << s[i] << " " << t[j] << endl;
            if(i == s.size()) return true;
            else if(t[j] == s[i]){
                i++;
                j++;
            }
            else if(t[j] != s[i]){
                j++;
            }          
        }
        if(i == s.size()) return true;
        
        return false;
    }
};