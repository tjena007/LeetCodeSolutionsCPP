class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(auto i : s){
            if(i == ')' && !st.empty() && st.top() == '(') st.pop();
            else if(i == '}' && !st.empty() && st.top() == '{') st.pop();
            else if(i == ']' && !st.empty() && st.top() == '[') st.pop();
            else st.push(i);
        }
        
        return st.empty();
    }
};