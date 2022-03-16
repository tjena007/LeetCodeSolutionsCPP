class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        map<int,bool> m;
        
        int j=0;
        for(auto i: popped){
            if(!m[i]){
                while(st.empty() || st.top() != i){
                    st.push(pushed[j]);
                    m[pushed[j]] = true;
                    j++;    
                }
                st.pop();
            }
            else if(st.top() == i){
                st.pop();
            }
            else{
                return false;
            }
        }
        
        
        return true;
    }
};