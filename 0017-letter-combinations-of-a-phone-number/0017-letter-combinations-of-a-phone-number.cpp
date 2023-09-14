class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        map<char,string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        
        vector<string> ans;
        string temp = "";
        
        helper(0,temp,ans,m,digits);
        
        return ans;
    }
    
    void helper(int idx, string& temp,vector<string>& ans,map<char,string>& m,string& digits){
        if(idx == digits.size()){
            ans.push_back(temp);
            return;
        }
        
        for(auto i : m[digits[idx]]){
            temp.push_back(i);
            helper(idx+1,temp,ans,m,digits);
            temp.pop_back();
        }
    }
};