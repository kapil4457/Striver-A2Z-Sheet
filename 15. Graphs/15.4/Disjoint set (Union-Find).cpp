//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int find(int a[],int x);
void unionSet(int a[],int x ,int z);
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		for(int i=1;i<=n;i++)
			a[i]=i;
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
			string s;
			cin>>s;
			if(s=="UNION"){
				int z,x;
				cin>>x>>z;
				unionSet(a,x,z);
			}
			else{
				int x;
				cin>>x;
				int parent=find(a,x);
				cout<<parent<<" ";
			}
		}
		cout<<endl;
	}
}
// } Driver Code Ends



    
    // vector<int>rank(1e9 , 0);
    // int findParent(int node , int parent[]){
    //     if(node == parent[node])return node;
    //     return parent[node] = findParent(parent[node] , parent);
    // }
    
    // void unionByRank(int u , int v , int parent[]){
    //     int ulp_u  = findParent(u, parent);
    //     int ulp_v  = findParent(v , parent);
    //     if(ulp_u==ulp_v)return;
    //     if(rank[ulp_u] < rank[ulp_v]){
    //         parent[ulp_u] = ulp_v;
    //     }else if(rank[ulp_v] < rank[ulp_u]){
    //         parent[ulp_v] = ulp_u;
    //     }else{
    //         parent[ulp_v] = ulp_u;
    //         rank[ulp_u]++;
    //     }
    // }


/*Complete the functions below*/
int find(int A[],int X)
{
       //add code here
      if(A[X]==X)return X;
      return A[X] = find(A , A[X]);
}
void unionSet(int A[],int X,int Z)
{
	//add code here.
//add code here.
	X=find(A,X);
	Z=find(A,Z);
	A[X]=Z;
	
	 
}


