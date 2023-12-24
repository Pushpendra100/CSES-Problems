#include <bits/stdc++.h>
using namespace std;

// determine for each node the maximum distance to another node.
// we will be doing this using the tree diameter
// Once we have a diameter (a,b),output max(dist(a,i),dist(b,i)) for each node i
// https://www.youtube.com/watch?v=Rnv4qvoxsTo

const int mxN = 2e5+10;
vector<int> g[mxN];
int d[2][mxN];

void dfs(int v, int l, int par = -1){
    for(int child: g[v]){
        if(child==par) continue;
        d[l][child] = d[l][v] + 1;
        dfs(child,l, v);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    for (int i = 0; i < n-1; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0); // we call dfs considering any one as root node, here we considered 1
    int mx_depth = -1;
    int mx_d_node;
    for(int i = 1; i<=n; i++){
        if(mx_depth<d[0][i]){
            mx_depth = d[0][i];
            mx_d_node = i;
        }
        d[0][i] = 0;
    }

    dfs(mx_d_node, 0); // 1st end of diameter
    mx_depth = -1;
    for(int i = 1; i<=n; i++){
        if(mx_depth< d[0][i]){
            mx_depth = d[0][i];
            mx_d_node = i;
        }
    }
    dfs(mx_d_node, 1); // 2nd end of diameter
 
    for(int i = 1; i<=n; i++){
        cout<<(max(d[0][i], d[1][i]))<<" ";
    }

    return 0;
}