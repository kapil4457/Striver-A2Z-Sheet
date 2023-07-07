//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    
    int f (vector<vector<int>>&points , int day , int last  , vector<vector<int>>&dp ){
        // This means that we are at the alst level in the vector
        if(day == 0){
            int maxi = INT_MIN;
            for(int i =0 ; i < points[0].size() ; i ++){
                if(i!=last){

                maxi = max(maxi , points[day][i]);
                }
            }
            return maxi;
        }
        if(day < 0)return 0;
        
        if(dp[day][last]!=-1)return dp[day][last];
        
        int maxi = INT_MIN;
        for(int i =0 ; i < points[0].size()  ; i++){
            if(i!=last){
            maxi = max(maxi , points[day][i] +  f(points , day-1 , i  ,dp) );
            }
        }
        
        return dp[day][last] =  maxi;
        
    }
  
  
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        // memoization : 
        
      vector<vector<int>>dp( n+1 , vector<int>(4 , -1));
      int maxi = INT_MIN;
      return f(points , n-1 , 3 , dp);
       
       

    
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends