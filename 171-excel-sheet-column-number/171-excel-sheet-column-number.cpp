class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans=0;
        int e = 0;
        for(int i=columnTitle.size()-1;i>=0;i--){
            // cout << columnTitle[i] - 'A' << endl;
            int cval = columnTitle[i] - 'A' + 1;
            int prod = pow(26,e);
            ans+= prod* cval;
            e++;
        }
        
        
        
        return ans;
        
    }
};