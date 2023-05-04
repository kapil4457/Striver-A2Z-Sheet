//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int subarrayCount(vector<int> &arr, int N, int k) {
        // code here
        int head = 0 , tail = 0 , ans =0 ;
        map<int,int>mpp;
        set<int>s;
        
        for(head = 0 ; head < N ; head++){
            mpp[arr[head]]++;
            s.insert(arr[head]);
            
            // If there are k uniques elements in the subarray
            if(s.size()==k){
                int tempTail = tail;
                map<int,int>ref = mpp;
                set<int>st = s;
                int localAns = 0;
                while(st.size()==k){
                    ref[arr[tempTail]]--;
                    if(ref[arr[tempTail]]==0){
                        st.erase(arr[tempTail]);
                    }
                    localAns++;
                    tempTail++;
                }
                
                ans+=localAns;
            }
            // If there are more uniques element in the subarray than k
            else if(s.size() > k){
                while(s.size()!=k){
                    mpp[arr[tail]]--;
                    
                    if(mpp[arr[tail]]==0){
                        s.erase(arr[tail]);
                    }
                    tail++;
                }
                
                int tempTail = tail;
                map<int,int>ref = mpp;
                set<int>st = s;
                int localAns = 0;
                while(st.size()==k){
                    ref[arr[tempTail]]--;
                    if(ref[arr[tempTail]]==0){
                        st.erase(arr[tempTail]);
                    }
                    localAns++;
                    tempTail++;
                }
                
                ans+=localAns;
                
                
                
                
            }
            // If there are less uniques element in the subarray than k
            else{
                // mpp[arr[head]]++;
                continue;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayCount(arr, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends