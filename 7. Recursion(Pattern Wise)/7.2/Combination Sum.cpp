//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    
    
    void solve(vector<int>&A,int N,int currsum,int B,int index,vector<vector<int>>&ans,vector<int>&temp){
         
         if(index>=N){
             if(currsum==B){
                 ans.push_back(temp);
             }
             return;
         }
         
         if(currsum<=B){
             temp.push_back(A[index]);
             solve(A,N,currsum+A[index],B,index,ans,temp);
             temp.pop_back();
         }
         solve(A,N,currsum,B,index+1,ans,temp);
         
         
     }
      vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        set<int>s(A.begin(),A.end());
        vector<int>arr(s.begin(),s.end());
        vector<vector<int>>ans;
        int N=arr.size();
        vector<int>temp;
        
        
        
        solve(arr,N,0,B,0,ans,temp);
        return ans;
      }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends