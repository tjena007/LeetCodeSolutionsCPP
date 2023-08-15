class Solution {
public:
    int compress(vector<char>& chars) {
        int count =0;
        
        int i=0;
        while(i<chars.size()){
            if(count == 0){
                int init = i+1;
                count++;
                i++;
                while(i<chars.size() && chars[i] == chars[i-1]){
                    count++;
                    i++;
                }
                if(i == init || count == 1){
                    count =0;
                    continue;
                }
                else{
                    string num = to_string(count);
                    for(int j=0;j<num.size();j++){
                        chars.insert(chars.begin()+init,num[j]);
                        init++;
                        i++;
                    }
                    if(i == chars.size()){
                        chars.erase(chars.begin() + init,chars.end()); 
                    }
                    else{
                        chars.erase(chars.begin() + init, chars.begin()+i);
                    }
                    i = init;
                    count = 0;
                }    
            }        
        }
        
        return chars.size();
    }
};