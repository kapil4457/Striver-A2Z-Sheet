#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mod 1000000007ll //998244353ll
#define mii map<int, int>
#define pii pair<int, int>
int power(int a,int b){int result =1; while(b>0){if(b%2) result*=a; a*=a;b/=2;} return result;}
using namespace std;


struct Node{
    int data;
    Node*left;
    Node*right;


        Node(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};

    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	
    	int dir = 1;
    	vector<int>ans;
    	queue<Node*>q;
    	if(root==NULL)return ans;
    	q.push(root);
    	q.push(NULL);
    	    vector<int>thisLevel;
    	while(!q.empty()){
    	    
    	   
    	        while( !q.empty() && q.front()!=NULL){
    	            if(q.front()->left){
    	                q.push(q.front()->left);
    	            }
    	             if(q.front()->right){
    	                q.push(q.front()->right);
    	            }
    	            thisLevel.push_back(q.front()->data);
    	            q.pop();
    	        }
				q.pop();

				if(!q.empty() && q.front()!=NULL){

				q.push(NULL);
				}
				
    	        
    	        
    	        
    	   
    	        
    	        if(dir==0){
    	            reverse(thisLevel.begin() , thisLevel.end());
    	        }
    	        for(auto it : thisLevel ){
    	            ans.push_back(it);
    	        }
    	        thisLevel.clear();
    	        
    	        dir=!dir;


    	    
    	}
    	
    	return ans;
    }


int main()
{


Node*root = new Node(5);
root->left = new Node(8);
root->right = new Node(9);
root->left->left = new Node(4);
vector<int>ans = zigZagTraversal(root);
for(auto it : ans)cout<<it<<" ";
 return 0;
}