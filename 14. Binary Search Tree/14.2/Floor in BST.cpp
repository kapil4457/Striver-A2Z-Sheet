//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

int floor(Node *root, int x);

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;

        cout << floor(root, s) << "\n";
    }
}

// } Driver Code Ends


// Function to search a node in BST.

void helper(Node* root,int k,int &val)
{
    if(!root) return;
    if(root->data==k){
        val = root->data;
        return;
    }
    if(root->data < k){
        val =max(val ,  root->data);
        helper(root->right,k,val);
    }
    if(root->data > k){
        helper(root->left,k,val);
    }
}

int floor(Node* root, int input) {
    // Code here
     int val=INT_MIN;
    helper(root,input,val);
    if(val==INT_MIN) return -1;
    return val;
}
