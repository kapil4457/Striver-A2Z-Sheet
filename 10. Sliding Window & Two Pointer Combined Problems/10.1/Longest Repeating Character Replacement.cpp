//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string S, int K) {
int head =0  , tail = 0 , ans =0  , cnt[26]={};

for(head =0 ; head < S.length() ; head++){
    cnt[S[head]-'A']++;
    while(head-tail+1 - *max_element(cnt , cnt+26) >  K){
        cnt[S[tail]-'A']--;
        tail++;
    }
    ans = max(ans , head-tail+1);
    
    
}

return ans;
 }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends