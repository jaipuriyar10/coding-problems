#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node    //declare Node 
{
	Node *next;
	int data;
	Node(int data)
	{
		this->data=data;    // node value
		this->next=NULL;    // node pointer
	}
};
Node* addNode(Node *head, int value){
    Node *temp,*p;// declare two nodes temp and p
    temp = new Node(value);//createNode will return a new node with data = value and next pointing to NULL.
    if(head == NULL){
        head = temp;     //when linked list is empty
    }
    else{
        p  = head;//assign head to p 
        while(p->next != NULL){
            p = p->next;//traverse the list until p is the last node.The last node always points to NULL.
        }
        p->next = temp;//Point the previous last node to the new node created.
    }
    return head;
}
Node *merge(Node *a,Node *b)   // merge linked list with sorted order
{
        Node *result;         // temporary node
        if(a==NULL)
            return b;         // if a is NULL return b
        if(b==NULL)
            return a;         // if b is NULL return a
        if(a->data<=b->data)
        {   result=a;
            result->next=merge(a->next,b);   // choose minm of a node and b node
        }
        else
        {
            result=b;
            result->next=merge(a,b->next);
        }
        return result;       // return temporary node
}
void print(Node *head)       // function to print linked list
{
	while(head!=NULL)
	{
		if(head->next!=NULL)
		cout<<head->data<<"->";
		else
		cout<<head->data;
		head=head->next;
	}
}
int main()
{
	ll t;
	cout<<"Enter number of test cases: ";
	cin>>t;
	while(t--)
	{
		ll n;
		cout<<"Enter number of linked lists which you want to merge: ";
		cin>>n;
		ll x;
		vector<Node*> v1;
		for(ll i=0;i<n;i++)
		{	
			ll y;
			cout<<"Enter linked list "<<(i+1)<<" size: ";
			cin>>y;
			Node *root;
			cout<<"Enter its elements: ";
			for(int j=0;j<y;j++)
			{
			cin>>x;
			if(j==0)
			{root=new Node(x);}
			else
			root=addNode(root,x);
			}	
			v1.push_back(root);
		}
		
		if(v1.size()==1)
            print(v1[0]);
        if(v1.size()==0)
        cout<<"No linked list is present ";
        Node *head=merge(v1[0],v1[1]);
        for(int i=2;i<v1.size();i++)
        {
            head=merge(head,v1[i]);
            
        }
        cout<<"Final sorted lists: ";
        print(head);
		cout<<"\n";
	}
	return 0;
}
