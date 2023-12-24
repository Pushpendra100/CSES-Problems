#include <bits/stdc++.h>
using namespace std;

// Using Euler Tour and segment tree
// https://www.youtube.com/watch?v=XqkneOGIJG4

/*
        1
    2       3
4     5   6   7

   1   2   3   4   5   6   7
in 1   2   5   3   4   6   7

dfs - 1 2 4 5 3 6 7

in dfs array we can see that in[3] = 5 which is position in dfs array
and subtree[3] - 1 = 3 -1 = 2 
thus after in[3] = 5  + 2 gives its children 6 and 7 

*/

#define int long long

int subtree[200001];
int in[200001];
vector<int> value(200001,0);
vector<int> flatten;


int dfs(vector<vector<int>>& adj, int u, int par, int& timer){
    subtree[u]+=1;
    in[u] = timer;
    timer++;
    flatten.push_back(u);
    for(int x: adj[u]){
        if(x!=par){
            subtree[u]+=dfs(adj, x, u, timer);
        }
    }
    return subtree[u];
}


int build_tree(int s, int e, int treenode, vector<int>&value, vector<int>& tree){
    int mid = s + (e-s)/2;
    if(s>e) return 0;
    if(s==e){
        tree[treenode] = value[flatten[s]];
        return tree[treenode];
    }
    tree[treenode] += build_tree(s, mid, 2*treenode, value, tree);
    tree[treenode] += build_tree(mid+1, e, 2*treenode + 1, value, tree);
    return tree[treenode]; 
}//O(nlogn)

int query_tree(int s, int e, int qs, int qe, int treenode, vector<int>& tree){
    if(s>=qs&&e<=qe){
        return tree[treenode];
    }
    if(s>qe || e<qs) return 0;
    int mid = s + (e-s)/2;
    return query_tree(s, mid, qs, qe,2*treenode, tree) + query_tree(mid+1, e, qs, qe, 2*treenode+1, tree);
}// O(logn)

void update(int s, int e, int node, int value, int treenode, vector<int>& tree){
    if(e<node || s>node) return;
    if(s==node&&s==e){
        tree[treenode]+=value;
        return;
    }
    int mid = s + (e-s)/2;
    update(s, mid, node, value, 2*treenode, tree);
    update(mid+1, e, node, value, 2*treenode+1, tree);
    tree[treenode] = tree[2*treenode]+tree[2*treenode+1];
}//O(logn)

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;


    for(int i = 1; i<=n; i++){
        cin>>value[i];
    }
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> tree(800001, 0);
    int timer = 0;
    dfs(adj, 1, -1, timer);
    build_tree(0, n-1, 1, value, tree);
    while (q--)
    {
        int a, b, c;
        cin>>a;
        if(a==1){
            cin>>b>>c;
            update(0, n-1, in[b], c-value[b], 1, tree);
            value[b] = c;
        }else{
            cin>>b;
            cout<<query_tree(0, n-1, in[b], in[b]+subtree[b]-1, 1, tree)<<"\n";
        }
    }
    
    return 0;
}