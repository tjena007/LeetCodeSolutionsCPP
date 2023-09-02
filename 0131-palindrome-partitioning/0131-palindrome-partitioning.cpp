class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        
        calc(s,path,0,ans);
        
        return ans;
    }
    
    void calc(string& s,vector<string>& path,int index,vector<vector<string>>& ans){
        if(index == s.size()){
            ans.push_back(path);
            return;
        }
        
        for(int i=index;i<s.size();i++){
            if(palindrome(s,index,i)){
                path.push_back(s.substr(index,i-index+1));
                calc(s,path,i+1,ans);
                path.pop_back();
            }
        }
    }
    
    bool palindrome(string& s,int start,int end){
        while(start<=end){
            if(s[start++] != s[end--]) return false;
        }
        
        return true;
    }

};