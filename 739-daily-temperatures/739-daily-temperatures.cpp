class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        int n = temperatures.size();
        vector<int> temp(n,0);
        for(int i=n-1;i>=0;i--){
            
            if(st.empty()){
                temp[i] = -1;
                st.push({temperatures[i],i});
            }
            
            else if(temperatures[i] >= st.top().first){
                while(!st.empty() && (temperatures[i] >= st.top().first)){
                    st.pop();
                }
                if(st.empty()){
                    temp[i] = -1;
                    st.push({temperatures[i],i});
                }
                else{
                    temp[i] = st.top().second;
                    st.push({temperatures[i],i});
                }
            }
            
            else{
                temp[i] = st.top().second;
                st.push({temperatures[i],i});
            }
        
        }
        for(int i=0;i<n;i++){
            if(temp[i] == -1) temp[i]=0;
            else{
                temp[i] -= i; 
            }
        }
        // for(auto i : temp){
        //     cout << i << " ";
        // }
        
        return temp;
    }
};