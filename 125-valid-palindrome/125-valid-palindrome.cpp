class Solution {
public:
    bool isPalindrome(string s) {
        string pal = "";
        
        for(auto i: s){
            if((i>='a' && i<='z') || (i>='A' && i<='Z') || (i>='0' && i<='9') ){
                pal+=tolower(i);
            }
        }
        
        for(int i=0;i<pal.size()/2;i++){
            if(pal[i] != pal[pal.size()-1-i]) return false;
        }
        
        return true;
    }
};