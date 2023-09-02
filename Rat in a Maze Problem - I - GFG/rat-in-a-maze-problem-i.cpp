//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[n-1][n-1] == 0 || m[0][0] == 0) return {"-1"};
        vector<string> paths;
       
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        
        int delrow[] = {1,0,0,-1};
        int delcol[] = {0,-1,1,0};
        
        calc(m,vis,n,"",0,0,paths,delrow,delcol);
        
        return paths;
    }
    
    void calc(vector<vector<int>> &m,vector<vector<bool>>& vis,int n,string cp,
    int row,int col,vector<string>& paths,int delrow[],int delcol[]){
        if(row == n-1 && col == n-1){
            paths.push_back(cp);
            return;
        }
        // vis[row][col] = 1;
        // D L R U
        
        string direction = "DLRU";
        
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            // cout << nrow << " " << ncol << "  ";
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && m[nrow][ncol] == 1 && !vis[nrow][ncol]){
                
                vis[row][col] = 1;
                calc(m,vis,n,cp+direction[i],nrow,ncol,paths,delrow,delcol);
                
                vis[row][col] = 0;
            }
        }
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends