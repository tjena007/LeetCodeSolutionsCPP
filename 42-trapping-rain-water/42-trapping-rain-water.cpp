class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        left[0] = height[0];
        right[n-1] = height[n-1];
        
        for(int i=1;i<height.size();i++){
            left[i] = max(height[i],left[i-1]);
        }
        
        for(int i=n-2;i>=0;i--){
            right[i] = max(height[i],right[i+1]);
        }
        
        vector<int> f(n,0);
        
        for(int i=0;i<n;i++){
            f[i] = min(left[i],right[i]) - height[i];
        }
        
        int ans = 0;
        
        for(auto i : f){
            ans+=i;
        }
        
        return ans;
        
    }
};