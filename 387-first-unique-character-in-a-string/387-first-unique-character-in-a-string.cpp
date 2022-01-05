class Solution {
public:
    int firstUniqChar(string s) {
        int index = -1;
        
        unordered_map<char,int> m;
        for(auto i: s){
            m[i]++;
        }
        
        // for(auto i : m){
        //     cout << i.first << " " << i.second << endl;
        // }
        
        for(int i=0;i<s.size();i++){
            if(m[s[i]] == 1){
                return i;
            }
        }
        
        return index;
    }
};