//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
 int atoi(string s) {
        int n = s.size();
        int num = 0;
        for(int i = 0; i<n; i++){
            if(i == 0 && s[i] == '-') continue;
            
            if(s[i] < '0' || s[i] > '9') return -1;
            else{
                int k = int(s[i] - '0');
                num = num*10 + k;
            }
        }
        if(s[0] == '-') num *= -1;
        return num;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends