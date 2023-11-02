#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5+10;
int n, dp0[mxN], dp1[mxN];
vector<int> adj[mxN];

void dfs(int u = 0, int p = -1){
    for (int v : adj[u])
    {
        if(v==p) continue;
        dfs(v, u);
        dp1[u] = max(dp1[u] + max(dp0[v], dp1[v]), dp0[u]+dp0[v]+1); 
        dp0[u]+= max(dp0[v], dp1[v]);
    }
}

int main() {

    cin>>n;
    for (int i = 1; i < n; i++)
    {
        int p, q;
        cin>>p>>q, --p, --q;
        adj[p].push_back(q);
        adj[q].push_back(p);
    }
    dfs();
    // for (int i = 0; i<n; i++)
    // {
    //     cout<<dp0[i]<<" ";
    // }
    // cout<<endl;
    // for (int i = 0; i<n; i++)
    // {
    //     cout<<dp1[i]<<" ";
    // }
    // cout<<endl;
    cout<<max(dp0[0], dp1[0]);

    return 0;
}