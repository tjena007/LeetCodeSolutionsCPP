class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> m;
        for(auto i: magazine){
            m[i]++;
        }
        
        for(auto i: ransomNote){
            if(m[i] == 0){
                return false;
            }
            else{
                m[i]--;
            }
        }
        
        return true;
    }
};