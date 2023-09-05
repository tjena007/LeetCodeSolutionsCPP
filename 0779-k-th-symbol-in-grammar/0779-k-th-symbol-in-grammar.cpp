class Solution {
public:
   int kthGrammar(int n, int k) {
        // string nums = "0";
        return calc(n,k);
    }
    
    int calc(int n,int k){
        if(n == 1){
            return 0;
        }
        
        int parent = calc(n-1,k/2 + k%2);
        
        bool isOdd = (k%2 == 1);
       if(parent == 0){
           return isOdd ? 0 : 1;
       }
       
       return isOdd ? 1 : 0; 
    }

};