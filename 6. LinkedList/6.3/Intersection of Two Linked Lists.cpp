//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}


// } Driver Code Ends
/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution{
  public:

     Node* findIntersection(Node* head1, Node* head2)
    {
        unordered_set<int> ans;
        
        struct Node*p=head1;
        struct Node*q=head2;
        int count=0;
        
        
        while(q)
        {
            ans.insert(q->data);
            q=q->next;
            
        }
        q=head2;
        
        while(p)
        {
            if(ans.find(p->data)!=ans.end())
            {     
              q->data=p->data;
              q=q->next;
              count++;
                
            }
            p=p->next;
            
        }
        p=head1;
        q=head2;
        
        for(int i=0;i<count;i++)
        {
            if(i==count-1)
            q->next=NULL;
            q=q->next;
            
        }
        return head2;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    
	    cin>> n;
	    Node* head1 = inputList(n);
	    
	    cin>>m;
	    Node* head2 = inputList(m);
	    Solution obj;
	    Node* result = obj.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends