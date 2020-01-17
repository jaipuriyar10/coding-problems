
void ans(Node *root,int d,map<int,vector<int>>&v)
{
    if(root==NULL)
    return ;
    v[d].push_back(root->data);
    if(root->left)
    ans(root->left,d+1,v);
    if(root->right)
    ans(root->right,d,v);
    return ;
}

void diagonalPrint(Node *root)
{
   // your code here
   map<int,vector<int>> v;
   ans(root,0,v);
   for(auto it=v.begin();it!=v.end();it++)
   {
       vector<int> v2=it->second;
       for(int i=0;i<v2.size();i++)
       cout<<v2[i]<<" ";
   }
   
}
