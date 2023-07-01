
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
    Node *left;
    Node *right;
    Node(int data){
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};


    void flatten(Node *root)
    {
     static Node *prev=NULL;
        //code here
             if(root==NULL)return;
        
        flatten(root->right);
        flatten(root->left);
        
        root->right =prev;
        root->left = NULL;
        prev = root;
        
    }



void display(Node * root){
    Node * ptr = root;
    while(ptr!=NULL){
        cout<<ptr->data<< " ";
        ptr = ptr->right;
    }
}
int main()
{

Node * root = new Node(1);
root->left = new Node(2);
root->right = new Node(5);

root->left->left = new Node(3);
root->left->right = new Node(4);

// root->right->left = new Node(6);
root->right->right = new Node(6);


flatten(root);
display(root);



 return 0;
}