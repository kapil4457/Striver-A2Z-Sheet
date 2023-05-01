//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        
        int l =0  , r = 0;
        int type1 = -1 , type2 = -1;
        int cnt1 = 0 , cnt2 =0 ;
        int ans =0 ;
        while(r < N){
                ans = max(ans , (cnt1+cnt2));
            if(fruits[r]!=type1 && fruits[r]!=type2){
                ans = max(ans , (cnt1+cnt2));
                if(type1==-1 || type2==-1){
                    if(type1==-1){
                        
                    type1=fruits[r];
                    cnt1++;
                    }else{
                        type2=fruits[r];
                        cnt2++;
                    }
                }else{
                ans = max(ans , (cnt1+cnt2));
                    if(type2==fruits[r-1]){
                        type1 =  fruits[r];
                        cnt1=1;
                    }else{
                        type2 = fruits[r];
                        cnt2=1;
                    }
                }
            }else{
                if(fruits[r]==type1){
                    cnt1++;
                }else{
                    cnt2++;
                }
            }
            
            r++;
        }
        
                ans = max(ans , (cnt1+cnt2));
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t=1;
    // cin >> t;
    while (t--) {
        int N=6;
        // cin >> N;
        // vector<int> fruits(N);
        vector<int> fruits={4,2,4,4,2,3};
        // for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends