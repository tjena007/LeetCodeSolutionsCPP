class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        //overlap +1
        int ans  = 0;
        sort(intervals.begin(),intervals.end());
        
        priority_queue<int,vector<int>,greater<int>> minh;
        
        for(int i=0;i<intervals.size();i++){
            if(minh.size()==0 || intervals[i][0] < minh.top()){
                ans++;
            }
            else{
                minh.pop();    
            }
            
            minh.push(intervals[i][1]);
        }
        
        
        return ans;
    }
};