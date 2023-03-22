//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  bool isValidSolution(vector<int>&bloomDay , int M , int K ,int day){
      int n = bloomDay.size();
      int adj = 0;
      int boq = 0;
      for(int i =0 ;  i < n ; i ++){
          if(bloomDay[i] <= day){
              adj++;
              if(adj == K){
                  boq++;
                  adj=0;
                  if(boq == M)return true;
              }
          }else{
              adj=0;
          }
          
      }
      return false;
  }
    int solve(int M, int K, vector<int> &bloomDay){
      // Code here
      
      if(M*K > bloomDay.size())return -1;
      int maxDaysRequired = 0;
      int l = 0 ; 
      int h;
      int n = bloomDay.size();
      for(int i =0 ; i < n ; i ++){
          maxDaysRequired = max(maxDaysRequired , bloomDay[i]);
      }
      
      
      h = maxDaysRequired;
      int ans = INT_MAX;
      while(l <= h){
          int m = l+(h-l)/2;
          
          if(isValidSolution(bloomDay , M , K , m)){
              ans = min(ans , m);
              h = m-1;
          }else{
              l = m+1;
          }
          
      }
      
      if(ans == INT_MAX)return -1;
      return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends