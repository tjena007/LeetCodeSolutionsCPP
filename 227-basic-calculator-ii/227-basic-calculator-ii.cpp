class Solution {
public:
    int calculate(string s) {
        stack<string> st;
        int ans = 0; 
        string n = "";
    
        for(int i=0;i<s.size();i++){
           if(s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/'){
                n+=s[i];
            }
            else{
                if(n!= "")st.push(n);
                n="";
                if(s[i] == '*' || s[i] == '/'){
                    int j=i+1;
                    string n2= "";
                    while(j < s.size() && s[j] != '+' && s[j] != '-' && s[j] != '*' && s[j] != '/'){
                        // cout << s[j];
                        n2+=s[j];
                        j++;
                    }
                    int num2 = stoi(n2);
                    int num1 = stoi(st.top());
                    st.pop();
                    if(s[i] == '*'){
                         st.push(to_string(num1*num2));
                    }
                    else{
                        st.push(to_string(num1/num2));
                    }
                    // cout << j;
                    i=j-1;
                }
                else{
                    // cout << (s[i]);
                    string c = "";
                    c.push_back(s[i]);
                    st.push(c);
                }  
            } 
        }
        if(n!= "")st.push(n);
        
        stack<string> st2;
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }
        
        while(!st2.empty()){
            if(st2.top() == "-"){
                st2.pop();
                ans-= stoi(st2.top());
                st2.pop();
            }
            else if(st2.top() == "+"){
                st2.pop();
                ans+= stoi(st2.top());
                st2.pop();
            }
            else{
                ans = stoi(st2.top());
                st2.pop();
            }
        }
        
        return ans;
    }
};