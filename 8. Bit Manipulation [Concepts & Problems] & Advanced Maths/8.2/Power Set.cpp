//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	void helper(vector<string>&ans , string temp , string s , int n , int i){
	    
	    if(i==n){
	        if(temp!=""){
	        ans.push_back(temp);
	        };
	        return;
	    }
	    
	   // take
	   helper(ans , temp+s[i] , s , n, i+1);
	   
	   //not take
	   helper(ans , temp , s , n , i+1);
	   
	}
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string>ans;
		    string temp = "";
		    int n = s.length();
		    int i = 0;
		    helper(ans , temp , s , n , i);
		    sort(ans.begin()  , ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends