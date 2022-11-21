//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i] != s[j])return false;
            else{
                i++;
                j--;
            }
        }
        
        return true;
    }
    
    int helper(string& s, int i, int j,vector<vector<int>>& mat){
        if(mat[i][j] != -1)return mat[i][j];
        if(i>=j)return mat[i][j]=0;
        if(isPalindrome(s,i,j) == true)return mat[i][j]=0;
        
        int ans = INT_MAX;
        
        for(int k=i;k<=j-1;k++){
            int temp = 1 + helper(s,i,k,mat) + helper(s,k+1,j,mat);
            
            ans = min(ans,temp);
        }
        
        return mat[i][j] = ans;
        
    }
    int palindromicPartition(string str)
    {
        // code here
        int size = str.size();
        vector<vector<int>> mat(size+1,vector<int>(size+1,-1));
        
        return helper(str,0,str.size()-1,mat);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends