class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count  = 0;
        if(n ==0) return true;
        if(n > flowerbed.size()) return false;
        if(flowerbed.size() == 1 && n==1){
            if(flowerbed[0] == 0) return true;
            return false;
        }
        int i=0;
        while(i<flowerbed.size()){
            if(flowerbed[i] == 0){
                if(i == flowerbed.size() - 1 && flowerbed[i-1] == 0){
                    count++;
                    break;
                }
                else if(i==0 && flowerbed[i+1] == 0){
                    count++;
                    i+=2;
                }
                else if(i>0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                    count++;
                    i+=2;
                } 
                else{
                    i++;
                }
            }
            else{
                i++;
            }
        }
        
        return count>=n;
    }
};