class Solution {
public:
    int kthGrammar(int n, int k) {
        // string nums = "0";
        if(n == 1 && k == 1)
            return 0;
        
        //length of the row
        int lengthOfRow = pow(2, n-1);
        //calculating the mid
        int mid = lengthOfRow/2;
        
        //if k belongs to the first half
        if(k <= mid){
            return kthGrammar(n-1, k);
        }
        //if k belongs to the second half
        else{
            return !(kthGrammar(n-1, k-mid));
        }
    }

};