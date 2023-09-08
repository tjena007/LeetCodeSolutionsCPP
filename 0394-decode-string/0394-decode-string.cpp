class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(auto i : s){
            if(i == ']'){
                string pattern = "";
                while(!st.empty() && st.top() != "["){
                    string k = st.top();
                    reverse(k.begin(),k.end());
                    pattern += k;
                    st.pop();
                }
                
                reverse(pattern.begin(),pattern.end());
                // cout << pattern << endl;
                st.pop();
                string num = "";
                while(!st.empty() && st.top()>="0" && st.top()<="9"){
                    num+=st.top();
                    st.pop();
                }
                reverse(num.begin(),num.end());
                int n = stoi(num);
                string s = "";
                for(int i=1;i<=n;i++){
                    s+=pattern;
                }
                st.push(s);
            }
            else{
                string temp(1,i);
                st.push(temp);
            }
        }
        
        vector<string> words;
        string ans = "";
        while(!st.empty()){
            words.push_back(st.top());
            st.pop();
        }
        
        for(int i=words.size()-1;i>=0;i--){
            ans+= words[i];
        }
        
        return ans;
    }
};