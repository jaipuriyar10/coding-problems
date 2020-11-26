struct info
{
    int sz;
    int min;
    int max;
    int ans;
    bool isbst;
};
info solve(Node *root)
{
    if(root==NULL)
    {
        return {0,INT_MAX,INT_MIN,0,true};
    }
    if(root->left==NULL and root->right==NULL)
    {
        return {1,root->data,root->data,1,true};
    }
    info l=solve(root->left);
    info r=solve(root->right);
    info ret;
    ret.sz=(1+l.sz+r.sz);
    if(l.isbst==true and r.isbst==true and l.max<root->data and r.min>root->data)
    {
        ret.min=min(l.min,min(r.min,root->data));
        ret.max=max(l.max,max(r.max,root->data));
        ret.ans=ret.sz;
        ret.isbst=true;
        return ret;
    }
    else
    {
        ret.sz=max(l.sz,r.sz);
        ret.ans=max(l.ans,r.ans);
        ret.isbst=false;
        return ret;
    }
}
int largestBst(Node *root)
{
	//Your code here
    return solve(root).ans;
}
