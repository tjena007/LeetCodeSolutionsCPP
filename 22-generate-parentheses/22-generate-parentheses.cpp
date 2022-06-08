class Solution {
public:
    void gen(string p,int oc,int cc,int n){
        
        if(oc == n){
            while(oc!=cc){
                p+= ")";
                cc++;
            }
            
            ans.push_back(p); //push correct ans
            
        }
        else{
        
            string p1 = p;
            p1+="(";
            gen(p1,oc+1,cc,n);
            string p2 = p;
            p2+=")";
            cc++;
            if(oc==cc || oc>cc){
                gen(p2,oc,cc,n);    
            }
            //only call if equal open bracket
        }
    }
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        int oc=1;
        int cc=0;
        string p = "(";
        gen(p,oc,cc,n);
        
        return ans;
    }
};