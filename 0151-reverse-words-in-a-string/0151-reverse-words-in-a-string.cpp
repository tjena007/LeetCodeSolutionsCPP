class Solution {
public:
    string reverseWords(string s) {
       vector<string> words;
        string temp = "";
        for(auto i : s){
            if(i == ' '){
                if(temp != ""){
                    words.push_back(temp);
                    temp = "";
                }
            }
            else{
                temp+=i;
            }
        }
        if(temp != ""){
            words.push_back(temp);
            temp = "";
        }
        
        // for(auto i: words){
        //     cout << i << endl;
        // }
        reverse(words.begin(),words.end());
        string ans = "";
        
        for(auto i : words){
            ans+= i;
            ans+= " ";
        }
        ans.pop_back();
        return ans;
    }
};