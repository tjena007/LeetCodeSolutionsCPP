class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool ans=true;
        // if(s.size() == 1){
        //     return false;
        // }
        for(auto i: s){
            //cout << st.size() << endl;
            if(st.size()!=0 && i=='}' && st.top()=='{'){
                st.pop();
            }
            else if(st.size()!=0 && i==')' && st.top()=='('){
                st.pop();
            }
            else if(st.size()!=0 && i==']' && st.top()=='['){
                st.pop();
            }
            else{
                //cout << i << endl;
                st.push(i);
            }
        }
        
        if(st.size() != 0){
            ans=false;
        }
        
        
        
        return ans;
    }
};