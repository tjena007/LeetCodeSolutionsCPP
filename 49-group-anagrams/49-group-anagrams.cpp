class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        
        vector<string> s1 = strs;
        
        for(int i=0;i<strs.size();i++){
            sort(strs[i].begin(),strs[i].end());
        }
        
        // sort(strs.begin(),strs.end());
        
        map<string,vector<string>> m;
        
        for(int i=0;i<strs.size();i++){
            m[strs[i]].push_back(s1[i]);
        }
        
        for(auto i : m){
            vector<string> temp;
            for(int j=0;j<i.second.size();j++){
                temp.push_back(i.second[j]);
            }
            
            ans.push_back(temp);
        }
        
        
        return ans;
    }
};