#include <bits/stdc++.h>
using namespace std;

/*
Strongly Connected Components (SCC) - 
A strongly connected component is the component of a directed graph that has a path from every vertex to every other vertex in that component.

For finding strongly connected components in a directed graph in O(V+E) time
1. Kosaraju algorithm
2. Tarjan's algorithm

We are going to do this using kosaraju algorithm
steps are -
1. dfs
2. revers edges
3. dfs
*/

const int mxN = 1e5+10;
int n, m;
vector<int> adj[mxN], rev[mxN];
vector<bool> vis1(mxN, false), vis2(mxN, false);
vector<vector<int>> scc;
stack<int> s;

void dfs1(int u){
    vis1[u] = true;
    for(int v: adj[u]){
        if(!vis1[v]) dfs1(v);
    }
    s.push(u);
}

void dfs2(int u, vector<int> &sc){
    // cout<<u<<" "; // for printing the scc components
    sc.push_back(u);
    vis2[u] = true;
    for(int v: rev[u]){
        if(!vis2[v]) dfs2(v, sc);
    }
}

void kosaraju(){

    for(int i = 1; i<=n ;i++){
        if(!vis1[i]) dfs1(i);
    }

    while(!s.empty()){
        int curr = s.top();
        s.pop();
        if(!vis2[curr]){
            vector<int> sc;
            dfs2(curr, sc);
            scc.push_back(sc);
        }
    }
    
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
    kosaraju();

    if(scc.size()==1){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
        cout<<scc[1][0]<<" "<<scc[0][0]<<"\n";
        // and we have path from scc[0] to scc[1] to ...
        // thus our answer is scc[1] to scc[0]
    }

    return 0;
}