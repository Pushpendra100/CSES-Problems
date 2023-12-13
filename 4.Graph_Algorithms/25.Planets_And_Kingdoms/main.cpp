#include <bits/stdc++.h>
using namespace std;

// Again this question is based on strongly connected components

const int mxN = 1e5+10;
int n, m;
vector<int> adj[mxN], rev[mxN], kdm(mxN);
vector<bool> vis1(mxN, false), vis2(mxN, false);
stack<int> s;

void dfs1(int u){
    vis1[u] = true;
    for(int v: adj[u]){
        if(!vis1[v]) dfs1(v);
    }
    s.push(u);
}

void dfs2(int u, int kdm_ct){
    kdm[u] = kdm_ct;
    vis2[u] = true;
    for(int v: rev[u]){
        if(!vis2[v]) dfs2(v, kdm_ct);
    }
}

int kosaraju(){

    for(int i = 1; i<=n ;i++){
        if(!vis1[i]) dfs1(i);
    }

    int kdm_ct = 0; //kingdom counter
    while(!s.empty()){
        int curr = s.top();
        s.pop();
        if(!vis2[curr]){
            kdm_ct++;
            dfs2(curr, kdm_ct);
        }
    }
    return kdm_ct;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }
    int kingdoms = kosaraju();

    cout<<kingdoms<<"\n";
    for(int i = 1; i<=n; i++){
        cout<<kdm[i]<<" ";
    }

    return 0;
}