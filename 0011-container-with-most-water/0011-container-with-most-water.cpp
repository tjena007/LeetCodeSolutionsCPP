class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int area = INT_MIN;
        while(left < right){
            int narea = min(height[left],height[right]) * (right - left);
            area = max(narea,area);
            if(height[left] <= height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        
        return area;
    }
};