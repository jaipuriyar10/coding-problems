typedef long long ll;
Node* lca(Node *root,int n1,int n2)
{
    if(root==NULL)
    return NULL;
    if(root->data==n1||root->data==n2)
    return root;
    Node *left=lca(root->left,n1,n2);
    Node *right=lca(root->right,n1,n2);
    if(left)
    if(left!=NULL and right!=NULL)
    return root;
    if(left!=NULL)
    return lca(root->left,n1,n2);
    else
    return lca(root->right,n1,n2);
    
}
ll leve(Node *root,ll n1,ll level)
{
    if(root==NULL)
    return -1;
    if(root->data==n1)
    return level;
    ll left=leve(root->left,n1,level+1);
    if(left==-1)
    return leve(root->right,n1,level+1);
    return left;
}
int findDist(Node* root, int a, int b)
{
    // Your code here 
    
    Node *root1=lca(root,a,b);
    ll n1=leve(root1,a,0);
    ll n2=leve(root1,b,0);
    return (n1+n2);
}
