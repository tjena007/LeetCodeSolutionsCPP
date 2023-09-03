class Solution {
public:
    int minimumOperations(string num) {    
        int ans = num.size();
        int n = num.size();
        if(n == 1 && num !="0") return 1;
        for(int i = n - 1;i>=0;i--){
            for(int j = i-1;j>=0; j--){
                if(((num[j]-'0')*10 + (num[i]-'0')) % 25 == 0){
                    ans = min(n-j-2, ans);
                }
            }
            if(num[i] == '0') ans = min(ans, n - 1);
        }
        
        return ans;
    }
};