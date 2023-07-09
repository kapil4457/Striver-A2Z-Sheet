//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends




class Comparator {
  public :
  bool operator()(string a ,string b){
      return a.size() < b.size();
  }  
};

class Solution {
  public:
  
    bool compare(string a,string b)
    {
        if(a.length() != b.length()+1)
        {
            return false;
        }
        
        int first=0,second=0;
        while(first<a.length())
        {
            if(second < b.length() and a[first] == b[second])
            {
                first++;second++;
            }
            else
            {
                first++;
            }
        }
        if(first == a.length() and second == b.length())return true;
        else
        return false;
    }
    
    
    
  int f(int n , vector<string>&words , int prev_ind , int ind , vector<vector<int>>&dp){
      sort(words.begin()  , words.end() , Comparator()) ;
      if(ind==n)return 0;
      
      if(dp[ind][prev_ind+1]!=-1)return dp[ind][prev_ind+1];
      int take = 0;
      if(prev_ind==-1 || compare(words[ind] , words[prev_ind])){
          take = 1 + f(n , words , ind , ind+1 , dp);
      }
      int not_take = 0 + f(n , words , prev_ind , ind+1 ,dp);
      return dp[ind][prev_ind+1] = max(take , not_take);
  }
  
  
    int longestChain(int n, vector<string>& words) {
        // Code here
        int prev_ind = -1 , ind =0;
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
        return f(n , words, prev_ind , ind  , dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends