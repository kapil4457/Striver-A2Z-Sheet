#include <bits/stdc++.h>
using namespace std;



class Solution {
  private:
    bool isValid(vector<int> &piles, long long int speed, int hours){
        long long cnt = 0;
        
        for(auto pile: piles){
            cnt += pile / speed;
            if(pile % speed != 0)
                cnt++;
        }
        
        return (cnt <= hours);
    }
  public:
    int Solve(int N, vector<int>& piles, int H) {
        int start = 1;
        int end = 1e9;
        int res = -1;
        
        while(start <= end){
            long long int mid = start + (end-start)/2;
            if(isValid(piles, mid, H)){
                res = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        
        return res;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
