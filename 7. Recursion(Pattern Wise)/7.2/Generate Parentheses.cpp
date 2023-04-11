//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
 
    
    void helper(vector<string>&ans , int n , int i , vector<char>&help , int open , int close){
        if(open  < close)return;
        if(i==2*n){
           if(open==close){
                string temp = "";
                for(int i =0 ; i < 2*n ; i ++){
                    temp.push_back(help[i] );
                }
                ans.push_back(temp);
            }
            return;
        }
       
            help[i] = '(';
            helper(ans , n , i+1 , help , open+1,  close);
            help[i] = ')';
            helper(ans , n , i+1 , help,open , close+1);
        
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<char>help(2*n);
        vector<string>ans;
        helper(ans , n ,  0 , help  , 0 , 0);
        return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends