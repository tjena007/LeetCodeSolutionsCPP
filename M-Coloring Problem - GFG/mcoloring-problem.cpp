//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool checkColor(bool graph[101][101],int m, int n,int node,vector<int>& colors){
        if(node == n) return true;
        
        //check all colour for the node, if colour possible check next node
        for(int i=1;i<=m;i++){
            if(isSafe(graph,m,n,i,node,colors)){
                colors[node] = i;
                if(checkColor(graph,m,n,node+1,colors) ==true ) return true;
                colors[node] = 0;
            }
        }
        return false;
    }
    
    bool isSafe(bool graph[101][101],int m, int n,int c,int node,vector<int>& colors){
        
        for(int i=0;i<n;i++){
            if(i != node && graph[node][i] == 1 && colors[i] == c) return false;
        }
        
        return true;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> colors(n,0);
        return checkColor(graph,m,n,0,colors);
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends