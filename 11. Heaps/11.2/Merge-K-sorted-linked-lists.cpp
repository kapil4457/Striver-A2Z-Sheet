//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Compare{
public: 
  bool operator()(Node* one , Node* two){
        if(one->data > two->data){
            return true;
        }
        return false;
    }
};

class Solution{
  public:
    //Function to merge K sorted linked list.
  
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           priority_queue<Node* , vector<Node*> , Compare>pq;
           
           for(int i  =0 ; i < K ; i++){
               if(arr[i]!=NULL){
                   pq.push(arr[i]);
               }
           }
           
           Node * ans = NULL;
           Node * ptr = ans;
           
           while(!pq.empty()){
               Node * front = pq.top();
               pq.pop();
               Node* next = front->next;
               if(next!=NULL){
                   pq.push(next);
               }
               
               if(ptr==NULL){
                   ans = front;
                   ptr = ans;
               }else{
                   ptr->next = front;
                   ptr = ptr->next;
               }
           }
           
           return ans;
           
           
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t=1;
//    cin>>t;
   while(t--)
   {
	//    int N;
	//    cin>>N;
    //    struct Node *arr[N];
    //    for(int j=0;j<N;j++)
    //     {
    //        int n;
    //        cin>>n;

    //        int x;
    //        cin>>x;
    //        arr[j]=new Node(x);
    //        Node *curr = arr[j];
    //        n--;

    //        for(int i=0;i<n;i++)
    //        {
    //            cin>>x;
    //            Node *temp = new Node(x);
    //            curr->next =temp;
    //            curr=temp;
    //        }
   	// 	}
    int N =4;
    struct Node *arr[N];
    Node * firstListHead = new Node(1);
    firstListHead->next = new Node(2);
    firstListHead->next->next = new Node(3);


    Node * secondListHead = new Node(4);
    secondListHead->next = new Node(5);


    Node * thirdListHead = new Node(5);
    thirdListHead->next = new Node(6);


    Node * fourthListHead = new Node(7);
        fourthListHead->next = new Node(8);


    arr[0] = firstListHead;
    arr[1] = secondListHead;
    arr[2] = thirdListHead;
    arr[3] = fourthListHead;
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends