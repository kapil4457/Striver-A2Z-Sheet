//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        map<char, int> rank;
        rank['+']= rank['-']=0;
        rank['*']= rank['/']=1;
        rank['^']= 2;
        rank['(']= rank[')']= -1;
        // for(auto x: rank) cout<<x.second; cout<<endl;
        // Your code here
        stack <char> st;
        string res="";
        
        for(auto c: s){
            if(rank.count(c)==0){
                res+= c; continue;
            }
            if(c==')'){
                while(st.empty()==false and st.top()!= '('){
                    res+= st.top();
                    st.pop();
                }
                if(st.empty()==false and st.top()=='(') st.pop();
            }
            else if(c=='('){
                st.push(c); continue;
            }
            else{
                while(st.empty()==false and rank[st.top()]>=rank[c]){
                    res+= st.top();
                    st.pop();
                }
                st.push(c);
            }
            // if(st.empty()==false) cout<<st.top()<<" ";
            
        }
        
        while(!st.empty()){
            res+= st.top();
            st.pop();
        }
        
        return res;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends