//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree


// } Driver Code Ends
//Function to find the lowest common ancestor in a BST.
class Solution{
    public:
    
      
    int helper(Node*root , int n1 , int n2){
        
        
        if(root==NULL)return 0;
        
        if(root->data == n1 || root->data==n2){
            return 1;
        }
        int left = 0;
        int right =0 ;
        
           left +=helper( root->left , n1 , n2);
         right += helper( root->right,n1,n2);
        
        return left+right;
        
        
    }
    void solve(Node * &ans , Node * root  , int n1, int n2){
        
        
        if(root==NULL)return;

    int left = 0 , right = 0;
    
    if(n1 < root->data && n2 < root->data){
        
      left = helper(root->left , n1 , n2);
    }else if(n1 > root->data && n2 > root->data){
        
     right = helper(root->right , n1 , n2);
    }else{
    
ans = root;
return;
    }
        // if(root->data==n1 || root->data==n2){
        //     if(left||right){
        //         ans = root;
        //         return;
        //     }
        // }
     
     
     if(left==right && left!=0)ans = root;
     
     else if(left > right){
         solve(ans  , root->left , n1 , n2);
     }
     else {
         solve(ans , root->right , n1 , n2);
     }
        
      

    }
        Node* LCA(Node *root, int n1, int n2)
        {
            // code here
            Node *ans=NULL;
       
       solve(ans , root , n1,n2);
       if(ans==NULL)return new Node(-1);
       return ans;
        }

};


//{ Driver Code Starts.

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
        int l , h;
		getline(cin,s);
		scanf("%d ",&l);
		scanf("%d ",&h);
        Node* root = buildTree(s);
        Solution sol;
        int ans = sol.LCA(root, l, h)->data;
        cout<<ans<<endl;
    }
    return 1;
}
// } Driver Code Ends