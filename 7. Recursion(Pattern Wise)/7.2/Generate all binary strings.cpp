//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

// Checks for consecutive one's
bool isValid(int arr[] , int size){
    int i =0 ;
    while(i < size){
        if(arr[i]==1){
            int cnt = 0;
            
            while(arr[i]==1){
                cnt++;
                i++;
            }
            
            if(cnt > 1)return false;
        }else{
            i++;
        }
    }
    
    return true;
    
}
void printTheArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }
    cout << " ";
}
 
// Function to generate all binary strings
void generateAllBinaryStrings(int n, int arr[], int i)
{
    if (i == n) {
        if(isValid(arr , n)){
        printTheArray(arr, n);
        }
        return;
    }
 

    arr[i] = 0;
    generateAllBinaryStrings(n, arr, i + 1);
 
    
    arr[i] = 1;
    generateAllBinaryStrings(n, arr, i + 1);
}
 
// Driver Code

    void generateBinaryStrings(int num){
        //Write your code
        
        int arr[num];
        generateAllBinaryStrings(num , arr , 0);
        
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends