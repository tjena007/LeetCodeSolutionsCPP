class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        vector<int> res(n+1,-1);
        res[0] = 0;
        res[1] = 1;
        return calc(n,res);
    }
    
    int calc(int n, vector<int>& res){
        if(res[n] != -1) return res[n];
        
        return res[n] = calc(n-1,res) + calc(n-2,res);
    }
};