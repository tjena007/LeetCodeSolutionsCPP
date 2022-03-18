class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]] = i;
        }
        bool arr[26] = {false};
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(!st.empty() && s[i] < st.top() && arr[s[i]-'a'] == false){
                while(!st.empty() && m[st.top()]>i && s[i] < st.top()){
                    arr[st.top()-'a'] = false;
                    st.pop();
                }
            }
            if(arr[s[i]-'a'] == false){
                st.push(s[i]);
                arr[s[i]-'a'] = true;
            } 
        }
        
        string ans = "";
        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};