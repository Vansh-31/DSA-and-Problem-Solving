// Platform => Code studio
// Problem => Kill The Snipers
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define MOD 1e9+7
#define PI 3.14
using namespace std;
bool dfs(int node,int parent,vector<vector<int>> &adj,vector<bool> &visited,vector<bool> &RecStack)
{
    visited[node] = true;
    RecStack[node] = true;
    for(auto nbr : adj[node])
    {
        if(!visited[nbr])
        {
            if(dfs(nbr,node,adj,visited,RecStack))
            {
                return true;
            }
        }
        if(RecStack[nbr])
        {
            return true;
        }
    }
    return RecStack[node] = false;
}
bool canWin(int n, int m, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(n);
    vector<bool> visited(n,false);
    vector<bool> RecStack(n,false);
    for(int i = 0; i < m; i++ )
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].pb(v);
    }
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            if(dfs(i,i,adj,visited,RecStack))
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    
    return 0;
}