bool iscycle(int v,bool vis[],bool recstack[],vector<int> adj[])
{
    if(vis[v]==false)
    {
        vis[v]=true;
        recstack[v]=true;
        for(int i=0;i<adj[v].size();i++)
        {
            if(vis[adj[v][i]]==false and iscycle(adj[v][i],vis,recstack,adj))
            return true;
            else if(recstack[adj[v][i]])
            return true;
        }
    }
    recstack[v]=false;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    bool vis[V];
    bool recstack[V];
    memset(vis,false,sizeof(vis));
    memset(recstack,false,sizeof(recstack));
    for(int i=0;i<V;i++)
    {
        if(iscycle(i,vis,recstack,adj))
        return true;
    }
    return false;
    
}
