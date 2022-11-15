//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int m = str1.size(), n = str2.size();
	    vector<vector<int>> mat(m+1,vector<int>(n+1));
	    
	    for(int i=0;i<m+1;i++){
	        for(int j=0;j<n+1;j++){
	            if(i==0 || j==0)mat[i][j] = 0;
	        }
	    }
	    
	    for(int i=1;i<m+1;i++){
	        for(int j=1;j<n+1;j++){
	            if(str1[i-1] == str2[j-1]){
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
	    
	    return m+n - 2*lcs;
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends