//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        // sort(bills.begin() , bills.end());
        int fives =0 , tens =0 , twenties =0;
        
        for(int i =0 ; i < N ; i ++){
            if(bills[i]==5){
                fives++;
            }else if(bills[i]==10){
                if(!fives)return false;
                
                fives--;
                tens++;
                
            }else{
                twenties++;
                int currBal = 15;
                
                while(tens && currBal >= 10){
                    tens--;
                    currBal-=10;
                }
                
                  while(fives && currBal >= 5){
                    currBal-=5;
                    fives--;
                }
                
                if(currBal)return false;
                
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends