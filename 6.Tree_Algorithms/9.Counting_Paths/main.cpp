#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=8Nq3THy2Kw0
// Difference Array Technique (Prefix Sum) on Tree | Lowest Common Ancestor

/*
Observation - 
Path between two nodes A and B will definitely pass through their LCA

We are applying prefix sum technique on a tree - timestamp : 11:07
At LCA we need to put -1
and just above LCA we need to do -1 again to neutralise

We can store ans for every node using subtree 
*/

const int mxN = 2e5+10;
vector<int> g[mxN];
int value[mxN];


int find_lca(int a, int b, int **parent, int *level, int limit){
    if(level[a]>level[b]) swap(a, b);
    int d = level[b] - level[a];
    while (d>0)
    {
        int i = int(log2(d));
        b = parent[b][i];
        d -= (1<<i);    
    }
    if(a==b) return a;
    for(int i = limit-1; i>=0; i--){
        if(parent[a][i]!=-1 && (parent[a][i] != parent[b][i])){
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];   
}


void dfs_for_lca(int start, int *level, int parent, int **parent1){
    for(auto i: g[start]){
        if(i != parent){
            parent1[i][0] = start;
            level[i] = level[start] + 1;
            dfs_for_lca(i, level, start, parent1);
        }
    }
}

void dfs_for_ans(int u, int par = -1){
    for(int v: g[u]){
        if(v^par){
            dfs_for_ans(v, u);
            value[u] += value[v];
        }
    }
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    for (int i = 0; i < n-1; i++)
    {
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int limit = log2(n) + 1;
    int **parent = new int *[n+1];
    for(int i = 1; i<=n; i++){
        parent[i] = new int [limit];
        for(int j = 0; j<limit; j++)
            parent[i][j] = -1;
    }
    int *level = new int[n+1]();
    level[1] = 0;
    dfs_for_lca(1, level, -1, parent);
    for(int i = 1; i<limit; i++){
        for(int j = 1; j<=n; j++){
            int x = parent[j][i-1];
            if(x!=-1){
                parent[j][i] = parent[x][i-1];
            }
        }
    }

    while (m--)
    {
        int a, b;
        cin>>a>>b;
        int x = find_lca(a, b, parent, level, limit);
        value[a] += 1;
        value[b] += 1;
        value[x] -= 1;
        int y = parent[x][0];
        if(y!=-1) value[y] -= 1;
    }// O( q*logn)

    dfs_for_ans(1);
    for (int i = 1; i <=n; i++)
    {
        cout<<value[i]<<" ";
    }
    


    return 0;
}