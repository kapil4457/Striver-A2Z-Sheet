//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    
    // Simply find the distance previous greater number
    //Function to calculate the span of stockâ€™s price for all n days.
    vector<int> prevGreater(int price[] , int n)
    {
        stack<int> st;
        st.push(-1);
        
        vector<int> ans(n , -1);
        for(int i = 0;i<n;i++)
        {
            int element = price[i];
            while(st.top()!= -1 && price[st.top()] <= element)
            {
                st.pop();
            }
            
            ans[i] = st.top();
            st.push(i);
        }
        
        return ans;
    }
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
         vector<int> pGreater = prevGreater(price , n);
       vector<int> ans(n , 1);
       for(int i = 0;i<n;i++)
       {
           ans[i] = i - pGreater[i];
       }
       
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends