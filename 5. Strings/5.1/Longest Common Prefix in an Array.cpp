//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string shortest = arr[0];
        
        for(int  i = 1 ; i < N ; i ++){
            if(arr[i].length() < shortest.length()){
                shortest = arr[i];
            }
        }
        
        string ans = "";
        
        for(int i =0 ; i  < shortest.length() ; i ++){
            char temp = shortest[i];
            bool check = false;
            for(int j =  0 ; j < N  ; j ++){
                if(arr[j][i] != temp){
                    check = true;
                    break;
                }
            }
            
            if(check){
                break;
            }else{
                ans.push_back(temp);
            }
        }
        
        
        
        if(ans == "")return "-1";
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends