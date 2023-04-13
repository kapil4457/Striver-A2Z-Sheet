//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve( vector<string>&v,string str,vector<vector<int>> &m, int n,int row,int col){
        if(row<0 || col<0 || row>=n || col>=n || m[row][col]==0)return;
        if(row==n-1 && col == n-1){
            v.push_back(str);
            return;
        }
        m[row][col]=0;
        
        solve(v,str+'D',m,n,row+1,col);
        solve(v,str+'U',m,n,row-1,col);
        solve(v,str+'L',m,n,row,col-1);
        solve(v,str+'R',m,n,row,col+1);
   
        m[row][col]=1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> v;
        solve(v,"",m,n,0,0);
        return v;
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