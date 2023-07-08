#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mod 1000000007ll //998244353ll
#define mii map<int, int>
#define pii pair<int, int>
int power(int a,int b){int result =1; while(b>0){if(b%2) result*=a; a*=a;b/=2;} return result;}
using namespace std;

class Solution {
public:
    
    // Recursive
     int minSum(vector<vector<int>>& triangle , int i , int j ,int n){

        if(i == n-1 ){
            return  triangle[i][j];
        }
        
        
        int down =  minSum(triangle , i+1 , j ,  n) + triangle[i][j] ;
        int right = minSum(triangle,i+1 , j+1  , n) + triangle[i][j] ;
        
        return  min(down , right);
    }

    
    //Memoization
     int minSum(vector<vector<int>>& triangle , int i , int j , vector<vector<int>>&dp , int n){

        if(i == n-1 ){
            return  triangle[n-1][j];
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int down =  minSum(triangle , i+1 , j , dp , n) + triangle[i][j] ;
        int right = minSum(triangle,i+1 , j+1  ,dp , n) + triangle[i][j] ;
        
        return dp[i][j] =  min(down , right);
    }

    
    int minimumTotal(vector<vector<int>>& triangle) {
        int i = triangle.size();
        vector<vector<int>>dp(i , vector<int>(i,-1));
      return minSum(triangle ,0 ,0 , dp , i);
    }
};

int main()
{

 return 0;
}