#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node
{
    ll data;
    Node *left,*right;
    Node(ll data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
}*root;
void postorder(Node *root)
{
    if(root==NULL)
    return ;
    else
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
        
    }
}
void add(ll x)
{
    Node *newnode=new Node(x);
    if(root==NULL)
    root=newnode;
    else
    {
        Node *temp=root;
        while(1)
        {
            if(temp->data>x)
            {
                if(temp->left!=NULL)
                temp=temp->left;
                else
                {
                    temp->left=newnode;
                    break;
                }
            }
            else
            {
                if(temp->right!=NULL)
                temp=temp->right;
                else
                {
                    temp->right=newnode;
                    break;
                }
            }
        }
    }
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++)
        cin>>arr[i];
        for(ll i=0;i<n;i++)
        add(arr[i]);
        postorder(root);
        cout<<"\n";
        root=NULL;
    }
    return 0;
}
