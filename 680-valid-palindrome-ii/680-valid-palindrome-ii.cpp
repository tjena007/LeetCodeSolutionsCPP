class Solution {
public:
    bool checkPalindrome(string s){
        for(int i=0;i<=s.size()/2;i++){
            if(s[i] != s[s.size()-1-i]){
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        if(checkPalindrome(s)) return true;
        
        else{
            for(int i=0;i<=s.size()/2;i++){
                if(s[i] != s[s.size()-1-i]){
                    string s1 = s;
                    string s2 = s;
                    s1.erase(s1.begin()+i);
                    
                    if(checkPalindrome(s1)) return true;
                    
                    s2.erase(s2.begin()+ (s.size()-1-i));
                    
                    if(checkPalindrome(s2)) return true;
                    
                    return false;
                         
                }
            }
        }
        return false;
    }
};