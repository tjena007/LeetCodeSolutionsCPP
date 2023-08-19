class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        int init = 0;
        return helper(ans,init,rowIndex);
    }
    
    vector<int> helper(vector<int> ans,int init,int& rowIndex){
        if(init+1 > rowIndex+1){
            return ans;
        }
        int size = ans.size() + 1;
        vector<int> temp(size,0);
        temp[0] = 1;
        
        for(int i=1;i<size;i++){
            int val1=ans[i-1];
            int val2 = i==ans.size() ? 0 : ans[i];
            temp[i] = val1 + val2;
        }
        
        return helper(temp,init+1,rowIndex);
        
    }
};