class Solution {
public:
    string helper(string word){
        int n = word.size();
        for(int i=0;i<n/2;i++){
            swap(word[i],word[n-1-i]);
        }
        
        return word;
    }
    string reverseWords(string s) {
        string word = "";
        string ans="";
        
        for(int i=0;i<s.size();i++){
            if(s[i]== ' '){
                ans+= helper(word)+' ';
                word="";
            }
            else{
                word+=s[i];
            }
        }
        ans+=helper(word);
        
        
        return ans;
    }
};