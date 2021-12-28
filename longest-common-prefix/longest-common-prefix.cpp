class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int j=0;
        bool flag = true;
        
        if(strs.size() == 1){
            return strs[0];
        }
        
        while(flag && j<strs[0].size()){
            for(int i=0;i<strs.size()-1;i++){
                if(strs[i]=="" || strs[i+1]==""){
                    return "";
                }
                if(strs[i][j] != strs[i+1][j]){
                    // cout << strs[i][j] << " " << strs[i+1][j];
                    flag= false;
                }
            }
            if(flag == true){
                //cout << strs[0][j] << endl;
                ans+=strs[0][j];
                j++;    
                //cout << j << endl;
            }
        }
        
        return ans;
    }
};