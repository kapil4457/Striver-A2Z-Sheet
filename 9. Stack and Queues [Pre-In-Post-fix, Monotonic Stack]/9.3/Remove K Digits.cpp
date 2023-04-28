//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int K) {
        
        int n = S.length();
        stack<char>st;
        
        for(int i =0 ; i < n ; i ++){
        if(st.empty()){
            if(S[i]!='0'){
                st.push(S[i]);
            }
        }else{
            
            while(!st.empty() && st.top() > S[i] && K!=0){
                st.pop();
                K--;
            }
            if(st.empty() && S[i]=='0'){
                continue;
            }else{
                st.push(S[i]);
                
            }
        }    
            
        }
        
        if(K!=0){
            while(K!=0 && !st.empty()){
                st.pop();
                K--;
            }
        }
        
        
        string ans = "";
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        if(ans=="")return "0";
        reverse(ans.begin() , ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends