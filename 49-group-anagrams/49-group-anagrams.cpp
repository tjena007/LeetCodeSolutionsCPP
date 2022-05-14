class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> m;
        for(auto i : strs){
            
            vector<int> c(26,0);
            for(auto j : i){
                c[j-'a']++;
            }
            
            string key = "";
            for(auto k : c){
                key+= to_string(k) + '#';
            }
            
            // cout << key << endl;
            m[key].push_back(i);
        }
        
        vector<vector<string>> ans;
        
        for(auto i : m){
            vector<string> st;
            for(auto j : i.second){
                st.push_back(j);
            }
            ans.push_back(st);
        }
        
        
        return ans;
        
    }
};