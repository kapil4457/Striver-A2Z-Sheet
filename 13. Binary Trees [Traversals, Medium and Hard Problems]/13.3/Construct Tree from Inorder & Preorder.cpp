//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
  Node* solve(int in[], int pre[], int n, int &index, int s, int e, unordered_map<int, vector<int>> &m){
        if(index>=n || s>e)
            return NULL;
            
            int element = pre[index++];
            Node* root = new Node(element);
            int pos = -1;
            if(m[element][0] == INT_MIN){
                 pos = m[element][1];
                m[element][1] = INT_MIN;
            }
            else{
                pos = m[element][0];
                m[element][0] = INT_MIN;
            }
                
            root->left = solve(in, pre, n, index, s, pos-1, m);
            root->right = solve(in, pre, n, index, pos+1, e, m);
            
            return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        unordered_map<int, vector<int>>index;
        for(int i= 0; i<n; i++)
            index[in[i]].push_back(i);
            
            int preindex = 0;
            return solve(in, pre, n, preindex, 0, n-1, index);
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends