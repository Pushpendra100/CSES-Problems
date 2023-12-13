#include <bits/stdc++.h>
using namespace std;

// Dp on graphs and SCC

/*
We can find solution of this problem using dp using dfs we can go deep and then while
returning store the values in dp array and compare and store value for their parents

But for applying dp in graph, we need to know that graph must be acyclic
Thus we need to find SCC and convert them into a single node
Now we can find out the max sum for coin collection
*/
#define ll long long

const int mxN = 1e5+10;
int n, m;
ll ans;
vector<int> adj[mxN], adj_t[mxN], adj2[mxN], comp(mxN); // in comp we are storing the lead node of every node, i.e. we will know that node i belong to which scc
vector<ll> coins(mxN), dp(mxN);
vector<bool>  vis(mxN, false);
stack<int> s;

void dfs1(int u){
    vis[u] = true;
    for(int v: adj[u]){
        if(!vis[v]) dfs1(v);
    }
    s.push(u);
}

void dfs2(int u, int new_node){
    vis[u] = true;
    comp[u] = new_node;
    if(u!=new_node) coins[new_node] += coins[u];
    for(int v: adj_t[u]){
        if(!vis[v]) dfs2(v, new_node);
    }
}


int kosaraju(){
    for(int i = 1; i<=n; i++){
        if(!vis[i]) dfs1(i);
    }
    vis.assign(mxN, false);
    int start = -1;
    while (!s.empty())
    {
        int t = s.top();
        s.pop();
        if(!vis[t]){
            if(start==-1) start = t;
            dfs2(t, t);
        }
    }
    return start;
}

void dfs3(int u){
    vis[u] = true;
    for(int v: adj2[u]){
        if(!vis[v]) dfs3(v);
        dp[u]=max(dp[u], dp[v]);
    }
    dp[u] += coins[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for (int i = 1; i <= n; i++) cin>>coins[i];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj_t[b].push_back(a);
    }
    // kosaraju gives topological order of scc
    kosaraju();

    // this is making a new adjacency list which is dag(directed acyclic graph) of scc
    for (int i = 1; i <=n; i++)
    {
        for(int v: adj[i]){
            if(comp[i]!=comp[v]){
                adj2[comp[i]].push_back(comp[v]);
            }
        }
    }
    vis.assign(mxN, false);
    // doing dfs from every ssc node which is not visited
    for(int i = 1; i<=n; i++){
        if(!vis[i] && comp[i]==i){
            dfs3(i);
            ans = max(ans, dp[i]);
        }
    }
    cout<<ans<<"\n";
    return 0;
}