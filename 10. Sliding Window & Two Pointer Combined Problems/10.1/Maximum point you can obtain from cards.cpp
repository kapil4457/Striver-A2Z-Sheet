//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  
  public:
    long long maxScore(vector<int> &cardPoints, int N, int K) {
        // code here
            long long res,ans=0;
        for(int i=0;i<K;i++){
            ans+=cardPoints[i];
        }
        res=ans;
        int i=K-1,j=N-1;
        while(i>=0){
            ans-=cardPoints[i];
            i--;
            ans+=cardPoints[j];
            j--;
            res=max(res,ans);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends