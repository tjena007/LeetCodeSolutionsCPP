class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        string fizz = "Fizz", buzz = "Buzz",fb = "FizzBuzz";
        
        for(int i=1;i<=n;i++){
            if(i%3 == 0 && i%5==0){
                ans.push_back(fb);
            }
            else if(i%3 == 0){
                ans.push_back(fizz);
            }
            else if(i%5 == 0){
                ans.push_back(buzz);
            }
            else{
                ans.push_back(to_string(i));
            }
        }
        
        return ans;
    }
};