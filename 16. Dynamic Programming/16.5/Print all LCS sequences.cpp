//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void f(set<string>&ref , string currStr , int n , int m , string s , string t){
	    if(n < 0 || m < 0 && currStr!=""){
	            reverse(currStr.begin() , currStr.end());
	        if(ref.size()==0){
	        ref.insert(currStr);
	        }else{
	             auto it = ref.begin();
	            string temp = *it;
	            
	            if(currStr.length() > temp.length()){
	                ref.clear();
	                ref.insert(currStr);
	            }else if(currStr.length()==temp.length()){
	                ref.insert(currStr);
	                
	            }
	        }
	        return;
	        
	    }

	    
	    if(s[n]==t[m]){
	        currStr.push_back(s[n]);
	        f(ref , currStr , n-1 , m-1 , s, t);
	        currStr.pop_back();
	    }else{
	        
	        f(ref , currStr , n , m-1 , s , t);
	        f(ref , currStr , n-1 , m , s , t);
	    }
	    }
	    
	    
	    
	
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    // Code here
		    set<string>ref;
		    int n = s.length();
		    int m = t.length();
		    f(ref , "" ,  n-1, m-1 , s ,t);
		    vector<string>ans(ref.begin() ,  ref.end());
		    sort(ans.begin()  , ans.end());
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends