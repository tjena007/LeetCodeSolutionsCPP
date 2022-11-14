//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        //find lcs
        vector<vector<int>> mat(m+1,vector<int>(n+1));
        
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0){
                    mat[i][j] = 0;
                }
            }
        }
        
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(X[i-1] == Y[j-1]){
                    mat[i][j] = 1 + mat[i-1][j-1];
                }
                else{
                    mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
                }
            }
        }
        
        int lcs = 0;
        
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                lcs = max(lcs,mat[i][j]);
            }
        }
        //cout <<"here " << lcs << endl; 
        
        return m+n-lcs;
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends