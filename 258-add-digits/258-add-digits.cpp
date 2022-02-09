class Solution {
public:
    int addDigits(int num) {
        while(num>=10){
            int sum=0;
            int num1 = num;
            while(num1>0){
                int rem = num1%10;
                sum+=rem;
                num1/=10;
            }
            
            num = sum;
        }
        
        return num;
    }
};