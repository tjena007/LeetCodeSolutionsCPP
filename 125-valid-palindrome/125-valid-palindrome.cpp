class Solution {
public:
    bool isPalindrome(string s) {
        string s1;
        for(auto i: s){
            if((i>= 'a' && i<='z') || (i>= 'A' && i<='Z') || (i>= '0' && i<='9') ){
                s1+=i;
            }
        }
        transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
        for(auto i : s1){
            cout << i ;
        }
        string s2 = s1;
        reverse(s2.begin(),s2.end());
        
        return (s2==s1);
    }
};