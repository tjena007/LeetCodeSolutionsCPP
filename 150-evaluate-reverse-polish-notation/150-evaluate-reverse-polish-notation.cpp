class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for(auto i : tokens){
            if(i == "+"){
                int n2 = st.top();
                st.pop();
                int n1 = st.top();
                st.pop();
                st.push(n1+n2);
            }
            else if(i == "-"){
                int n2 = st.top();
                st.pop();
                int n1 = st.top();
                st.pop();
                st.push(n1-n2);
            }
            else if(i == "*"){
                int n2 = st.top();
                st.pop();
                int n1 = st.top();
                st.pop();
                st.push(n1*n2);
            }
            else if(i == "/"){
                int n2 = st.top();
                st.pop();
                int n1 = st.top();
                st.pop();
                st.push(n1/n2);
            }
            else{
                st.push(stoi(i));
            }
        }
    
        return st.top();
    }
};