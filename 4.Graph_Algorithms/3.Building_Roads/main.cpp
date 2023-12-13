#include <bits/stdc++.h>
using namespace std;
// Connecting the connected components in the graph

const int N = 1e5+10;
int n, m;
vector<int> adj[N], ans;
bool vis[N];

void dfs(int u){
    vis[u] = 1;
    for (int v : adj[u])
    {
        if(!vis[v]) dfs(v);
    }
    
}

int main() {

    cin>>n>>m;
    for (int i = 0, a, b; i < m; i++)
    {
        cin>>a>>b, --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        if(!vis[i]){
            ans.push_back(i);
            dfs(i);
        }
    }
    cout<<ans.size() - 1<<"\n";
    for (int i = 1; i < ans.size(); i++)
    {
        cout<<ans[0]+1<<" "<<ans[i]+1<<"\n";
    }
    

    return 0;
}