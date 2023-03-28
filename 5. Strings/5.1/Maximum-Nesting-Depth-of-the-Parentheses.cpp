//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maxDepth(string s) {
        // code here
        stack<char>st;
        int size = 0;
        int n = s.length();
        int ans= INT_MIN;
        for(int i =0  ; i < n ; i ++){
            if(s[i]=='('){
                st.push('(');
                size++;
            }else if(s[i]==')'){
                st.pop();
                size--;
            }
            
            ans = max(ans , size);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t=1;
    // cin >> t;
    while (t--) {
        string s= "((5+2)(3+4)((6)))";
        // cin >> s;

        Solution obj;
        int ans = obj.maxDepth(s);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends