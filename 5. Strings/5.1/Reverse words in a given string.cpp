//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        int n = S.length();
        string temp = "";
        stack<string>ref;
        for(int i = 0 ; i < n ; i ++){
            if(S[i]=='.'){
                ref.push(temp);
                temp="";
            }else{
                temp+=S[i];
            }
        }
        ref.push(temp);
        string ans = "";
        
        while(!ref.empty()){
            ans+=ref.top();
            ans.push_back('.');
            ref.pop();
        }
        ans.pop_back();
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends