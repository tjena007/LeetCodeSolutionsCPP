class Solution {
public:
    int climbStairs(int n) {
        vector<int> res(n+1, -1);
        res[1] = 1;
        res[0] = 1;
        return calc(n,res);
        
    }
    
    int calc(int n, vector<int>& res){
        if(n<0) return 0;
        if(res[n] != -1) return res[n];
        
        return res[n] = calc(n-1,res) + calc(n-2,res);
    }
};

// 3
//2 + 1