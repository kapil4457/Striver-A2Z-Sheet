//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:


void dfs(vector<vector<int>>& image, int i, int j, int newColor,int color,int m,int n)
{
    if(i>=0 && j>=0 && i<m && j<n && image[i][j]==color && color!=newColor)
    {
        image[i][j]=newColor;
        dfs(image,i-1,j,newColor,color,m,n);
        dfs(image,i+1,j,newColor,color,m,n);
        dfs(image,i,j-1,newColor,color,m,n);
        dfs(image,i,j+1,newColor,color,m,n);
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m=image.size();
        int n=image[0].size();
      int color=image[sr][sc];
        dfs(image,sr,sc,newColor,color,m,n);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends