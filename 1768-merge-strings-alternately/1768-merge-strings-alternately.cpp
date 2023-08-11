class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int i=0,j=0;
        int s1 = word1.size(),s2=word2.size();
        
        while(i<s1 && j<s2){
            if(i==j){
                ans+=word1[i];
                i++;
            }
            else{
                 ans+=word2[j];
                j++;
            }
        }
        
        while(i<s1){
            ans+=word1[i];
            i++;
        }
        while(j<s2){
            ans+=word2[j];
            j++;
        }
        
        return ans;
    }
};