#include <bits/stdc++.h>
using namespace std;

// dp on graph

// https://www.youtube.com/watch?v=9HMawd5jn9A

/*
we will maintian a dp array and a next node array

             1   2     3    4   5   6   7    8   
dp          -1  -1   -1   -1  -1  -1  -1    1   
next-node  

dp[i] = longest path from node i to node n;
and next-node will store the next node to be taken for max length

thus if we are a node i say, then we can see its children and the children with the max dp value will give the max length and thus 
we can make a choice of path

so we will go deep down the nodes using dfs and then during returning back we will fill the dp and next-node array
dp[n] contains 1 thus when returning back the one who provides max path is kept dp[6] < dp[8] + 1; then dp[6] updated and next-node of 6 is set to 8
if dp[1] remains -1 it means that we are unable to reach node 8

if the node is visited then we will not make dfs call we will directly call for comparison of values
*/

int n, m;
vector<vector<int>> g;
vector<int> dp, next_node;
vector<bool> vis;


void dfs(int node){
    vis[node] = true;

    for(int v: g[node]){
        if(vis[v]==false) dfs(v);

        if(dp[v]!= -1 && dp[v]+1>dp[node]){
            dp[node] = dp[v]+1;
            next_node[node] = v;
        }
    }
}




int main() {

    cin>>n>>m;
    g.resize(n+1);
    dp.resize(n+1);
    next_node.resize(n+1);
    vis.resize(n+1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = -1;
    }
    
    dp[n] = 1;
    dfs(1);

    if(dp[1] == -1){
        cout<<"IMPOSSIBLE\n";
    }else{
        cout<<dp[1]<<"\n";
        int node = 1;
        while (node)
        {
            cout<<node<<" ";
            node = next_node[node];
        }
        
    }

    return 0;
}