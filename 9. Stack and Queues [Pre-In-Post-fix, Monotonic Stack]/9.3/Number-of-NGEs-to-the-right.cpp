//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        //write your code here
        stack<int>s1 ,s2;
        vector<int>ref(n);
        
        // 3,4,2,7,5,8,10,6
        // Calculate the NGE for all the elements
        for(int i =n-1 ; i >=0 ; i --){
            if(s1.empty()){
                s1.push(arr[i]);
                cout<<"Pushed into s1: "<< arr[i]<<endl;
                ref[i] = 0;
                cout<<"ref["<<i<<"] = "<<0<<endl;
                continue;
            }
            
            if(s1.top() > arr[i]){
                s1.push(arr[i]);
                cout<<"Pushed into s1: "<< arr[i]<<endl;

            }else{
                while(!s1.empty() &&s1.top() < arr[i] ){
                    s2.push(s1.top());
                    cout<<"Pushed into s2 and popped form s1: "<< s1.top()<<endl;
                    s1.pop();
                }
                
                ref[i] = s1.size();
                cout<<"ref["<<i<<"] = "<<s1.size()<<endl;
                s1.push(arr[i]);
                cout<<"Pushed into s1: "<< arr[i]<<endl;
                
                   while( !s2.empty()){
                    s1.push(s2.top());
                    cout<<"Pushed into s1 and popped form s2: "<< s2.top()<<endl;
                    s2.pop();
                }
            }
        }
        
        
        // Entertaining each querie;
        vector<int>ans;
        for(int i =0 ; i < queries ; i ++){
            ans.push_back(ref[indices[i]]);

        }
        
        return ans;
        //
    }

};

//{ Driver Code Starts.
int main(){
    int t = 1;
    // cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

// 8
// 3 4 2 7 5 8 10 6
// 2
// 0 5
    while(t--){
        //Input

       int n = 8; 
    //    cin >> n;
    //    vector<int> v1(n);
    //    for(int i = 0;i<n;i++) cin >> v1[i];
    //     int q; cin >> q;
    //     vector<int> v2(q);
    //     for(int i = 0;i<q;i++) cin >> v2[i];
       vector<int> v1={3,4,2,7,5,8,10,6};
        int q=2;
        vector<int> v2 = {0,5};

        Solution obj;

        vector<int> ans = obj.count_NGE(n,v1,q,v2);

        for(int i = 0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << endl;

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends