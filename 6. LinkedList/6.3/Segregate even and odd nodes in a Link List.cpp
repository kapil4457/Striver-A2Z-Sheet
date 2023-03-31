//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node * ptr = NULL;
        Node * currNode = head;
        Node *prev = NULL;
        
        // Checking if the first node is the even node...if it is then incrementing the ptr pointer
      if(currNode->data%2==0){
          ptr =  currNode;
          prev = currNode;
          currNode = currNode->next;
      }
      bool isOdd = false;

      
      while(currNode!=NULL){
          if(currNode->data%2==0){
              
            //   This means that it is the first positive node encountered
              if(ptr==NULL){                                                                                        
                  Node * newHead = currNode;
                  prev->next = currNode->next;
                  newHead->next = head;
                  head = newHead;
                  ptr= head;
                  currNode = prev->next;
              }else{
                  
                //   Ptr already exists
                if(prev->data%2==0){
                    prev = currNode;
                    ptr = currNode;
                    currNode = currNode->next;
                    continue;
                    
                }
                  Node* tempNode = currNode;
                  prev->next = currNode->next;
                  tempNode->next = ptr->next;                  
                  ptr->next = tempNode;
                  ptr = ptr->next;
                  currNode = prev->next;
                  
              }
          }else{
        //  If the node is odd , Update the previous node and update the currNode
                  prev=currNode;
                  currNode = currNode->next;
                  isOdd = true;
             
          }
      }
    
    return head;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends