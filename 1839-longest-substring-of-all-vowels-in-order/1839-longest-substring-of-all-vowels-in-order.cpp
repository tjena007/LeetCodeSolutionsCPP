class Solution {
public:
    int longestBeautifulSubstring(string word) {
        
        int ans = 0;
        vector<char> let = {'a','e','i','o','u'};
        int k=0;
        
        int j=0;
        int len = 0;
        while(j<word.size()){
            // cout << word[j] << endl;
             if(word[j] == let[k]){
                 len++;
                 // j++;
             }
             else if(k==4){
                 ans = max(len,ans);
                 len=0;
                 k=0;
                 // j++;
                 if(word[j] == 'a') len++;
                 
             }
             else if((len>0) && word[j] == let[k+1]){
                 len++;
                 k++;
                 // j++;
             }
             else{
                if(k == 4){
                    ans = max(len,ans);
                }
                len=0;
                k=0;
                if(word[j] == 'a') len++;
             }
            j++;
        }
        if(k == 4){
            ans = max(len,ans);
        }
        
        
        return ans;
    }
};