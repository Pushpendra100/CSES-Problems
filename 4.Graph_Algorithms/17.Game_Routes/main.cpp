#include <bits/stdc++.h>
using namespace std;

// dp on graph
// in how many ways you can reach from node 1 to node n in a directed acyclic graph

#define ll long long

int n, m;
vector<vector<int>> g;
vector<ll> dp; // now dp will store the no. of ways it can reach node n
vector<bool> vis;
const int M = 1e9+7;

void dfs(int node){
    vis[node] = true;
    for(int v: g[node]){
        if(vis[v]==false) dfs(v);

        dp[node] += (dp[v]%M);
    }
}


int main() {

    cin>>n>>m;
    g.resize(n+1);
    dp.resize(n+1);
    vis.resize(n+1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    dp[n] = 1;
    dfs(1);

     if(dp[1] == -1){
        cout<<"IMPOSSIBLE\n";
    }else{
        cout<<(dp[1]%M)<<"\n";
    }

    return 0;
}