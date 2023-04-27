//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string preToInfix(string pre_exp) {
        stack<string>st;
        int n=pre_exp.size()-1;
        for(int i=n;i>-1;i--)
        {
            char ch = pre_exp[i];
            if(ch=='^' || ch=='/' || ch=='*' || ch=='+' || ch=='-')
            {
                string exp = "(" + st.top() + ch;
                st.pop();
                exp += st.top() + ")";
                st.pop();
                st.push(exp);
            }
            else
            {
                string temp="";
                temp += ch;
                st.push(temp);
            }
        }
        return st.top();
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends