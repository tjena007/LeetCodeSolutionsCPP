class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long int sum=0;
        sum+= mass;
        for(int i=0;i<asteroids.size();i++){
            if(sum>=asteroids[i]){
                sum+=asteroids[i];
            }
            else{
                return false;
            }
        }
        
        return true;
    }
};