//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

void helper(vector<string>&ans , map<string,int>ref , string currString , int idx , string s){
    if(idx >= s.length()){
        currString.pop_back();
        ans.push_back(currString);
        return;
    }
    
    string temp = "";
    for(int i =idx ; i < s.length() ; i++){
        temp.push_back(s[i]);
        if(ref.find(temp)!=ref.end()){
            helper(ans , ref , currString+temp+" " , i+1 , s);
        }
    }
    
    
    
}
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        vector<string>ans;
        map<string , int>ref;
        for(auto it : dict){
            ref[it]++;
        }
        string currString = "";
        
        helper(ans , ref,currString , 0 , s);
        return  ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends