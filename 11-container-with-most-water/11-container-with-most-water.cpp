class Solution {
public:
    int maxArea(vector<int>& height) {
        int low=0,high = height.size()-1;
        int ans = INT_MIN;
        while(low < high){
            if(height[low] < height[high]){
                int area = (high-low) * height[low];
                ans = max(area,ans);
                low++;
            }
            else if(height[low] > height[high]){
                int area = (high-low) * height[high];
                ans = max(area,ans);
                high--;
            }
            else{
                int area = (high-low) * height[low];
                ans = max(area,ans);
                low++;
            }
        }
        
        return ans;
    }
};