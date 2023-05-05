//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        
        map<int,int>ref;
       
        int ans = 0;
        int head =0 , tail = 0;
        for(head =0 ; head < N ; head++){
            ref[fruits[head]]++;
            
            if(ref.size()==2){
               
                ans = max(ans , head-tail+1);
            }else if(ref.size() > 2){
             
             while(tail < head){
                 ref[fruits[tail]]--;
                 if(ref[fruits[tail]]==0){
                     ref.erase(fruits[tail]);
                     tail++;
                    ans = max(ans , head-tail+1);
                     break;
                 }
                 tail++;
             }   
            }
        }
        
        if(ref.size()==1)ans+=ref[fruits[0]];
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends