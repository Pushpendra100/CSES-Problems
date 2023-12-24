#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/sum-of-length-of-paths-from-every-node-to-all-other-nodes-using-tree-rerooting-technique/
// https://www.youtube.com/watch?v=nGhE4Ekmzbc


// dp on tree
// Sum of length of paths from every node to all other nodes using Tree Rerooting technique
// Rerooting is a dynamic programming technique in trees. Using this a property dp[i] on tree is calculated, when the tree is rooted at i.

// rerooting is done in O(1)
// Thus total time complexity O(N)

/*
Let's consider currently rooted at 1 and we have applied dfs and stored all the sum of distances and count of nodes for the subtree
        1
c1  c2  c3  c4....ci...ck

now we are rooting at ci
see,
partial(1|ci) = ans(1) - (subtree(ci) + nodes(ci))

ans(ci) = subtree(ci) + partial(1|ci) + (N - nodes(ci))
*/

#define ll long long

const int mxN = 2e5+10;
vector<int> g[mxN];
ll subtreeAns[mxN], ans[mxN];
int  subtreeSize[mxN];


void dfs(int u, int par = 0){
    int numOfNodes = 1;
    ll ansForSubtree = 0;
    for(int v: g[u]){
        if(v^par){
            dfs(v, u);
            numOfNodes+=subtreeSize[v];
            ansForSubtree+=subtreeAns[v] + subtreeSize[v]; 
        }
    }
    subtreeAns[u] = ansForSubtree;
    subtreeSize[u] = numOfNodes;
}

void solve(int src, int par, ll par_ans, int& totalNodes){
    ans[src] = subtreeAns[src] + (par_ans + (totalNodes - subtreeSize[src]));
    for(int child: g[src]){
        if(child^par){
            solve(child, src, ans[src]-(subtreeAns[child]+subtreeSize[child]), totalNodes);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    for(int i = 0; i<n-1; i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1);
    solve(1, 0, 0, n);

    for(int i = 1;i<=n; i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}