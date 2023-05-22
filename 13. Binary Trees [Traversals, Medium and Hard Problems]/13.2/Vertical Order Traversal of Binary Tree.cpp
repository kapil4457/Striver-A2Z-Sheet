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
        this->left = NULL;
        this->right = NULL;
    }
};


  
    struct Comparator{
        bool operator()(pair<Node * , pair<int,int>>&a , pair<Node * , pair<int,int>>&b){
            if(a.second.first > b.second.first){
                return true;
            }else if(a.second.first == b.second.first){
                if(a.second.second > b.second.second){
                    return true;
                }
            }
        
        return false;
        } 
    };
    
    
    void inOrder(       priority_queue<pair<Node * , pair<int,int>>   , vector<pair<Node * , pair<int,int>> >  , Comparator>&pq , Node * root , int verticalHeight , int horozontalHeight){
        
        
        if(root==NULL)return;
        
        pq.push({root , {verticalHeight , horozontalHeight}});
        
        inOrder(pq , root->left , verticalHeight-1 , horozontalHeight+1);
        inOrder(pq , root->right , verticalHeight+1 , horozontalHeight+1);
    }
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        
        // Node , {vecticalHeight , horizontalHeight}
       priority_queue<pair<Node * , pair<int,int>>   , vector<pair<Node * , pair<int,int>> >  , Comparator>pq;
       
       inOrder(pq , root , 0 , 0 );
       
       vector<int>ans;
       while(!pq.empty()){
        ans.push_back(pq.top().first->data);
        pq.pop();
       }
       
       return ans;
       
       
    }

int main()
{


    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->right->left = new Node(4);
    root->right->right = new Node(6);

    root->right->left->right = new Node(5);

    root->right->left->right->left = new Node(7);
    vector<int>ans = verticalOrder(root);
    for(auto it : ans)cout<<it<<" ";
 return 0;
}