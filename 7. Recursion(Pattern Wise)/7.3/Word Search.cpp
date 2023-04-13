//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool dfs(int row , int col , vector<vector<char>>& board , string word , vector<vector<int>> &vis, int l){
        
        if(l == word.size()) return true;
        
        vis[row][col]=1;
        int n = board.size();
        int m = board[0].size();
        vector<pair<int,int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};
        
        for(int i = 0 ; i<4 ;i++){
            int nrow = row + directions[i].first;
            int ncol = col + directions[i].second;
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]==word[l] &&vis[nrow][ncol]==0){
                if(dfs(nrow ,ncol ,board , word ,vis, l+1)){
                  return true;   
                }
            }
        }
        vis[row][col]=0;
        return false;
        
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
         vector<vector<int>> vis(n , vector<int>(m,0));
         for(int i=0 ; i<n;i++){
           
             for(int j = 0 ; j<m;j++){
                 if(board[i][j] == word[0]){
                     if(dfs(i , j , board , word , vis, 1)){
                         return true;
                     }
                 }
             }
         }
         
         
         return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends