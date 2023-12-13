#include <bits/stdc++.h>
using namespace std;

/*
Minimum spanning tree
A minimum spanning tree or minimum weight spanning tree is a subset of the edges of a connected, edge-weighted undirected graph that
connects all the vertices together, without any cycles and with the minimum possible total edge weight. That is, it is a spanning
tree whose sum of edge weights is as small as possible.

There are two algos for making a minimum spanning tree out of a weighted undirected graph
1. kruskal's minimum spanning tree (greedy algo) TC:- O(ElogE) where E is the no. of edges in graph
2. Prim's minimum spanning tree (greedy algo) TC:- O(ElogE)

Kruskal's algroithm
1. First, it sorts all the edges of the graph by their weights, 
2. Then starts the iterations of finding the spanning tree. 
3. At each iteration, the algorithm adds the next lowest-weight edge one by one, such that the edges picked until now does not form a cycle.
This algorithm can be implemented efficiently using a DSU ( Disjoint-Set ) data structure to keep track of the connected components of the graph.
*/

#define ll long long

const int N = 1e5+10;
int parent[N];
int siz[N];

void make(int v){
    parent[v] = v;
    siz[v] = 1;
}

int find(int v){
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(siz[a]<siz[b]) swap(a,b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin>>u>>v>>wt;
        edges.push_back({wt, {u, v}});
    }
    sort(edges.begin(), edges.end());
    for(int i = 1; i<=n; i++) make(i);

    ll total_cost = 0;
    int added_edge_ct = 0;
    for(auto &edge: edges){
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        // if u and v have same parent then on joining them loop will be created
        if(find(u)==find(v)) continue; 
        Union(u, v);
        added_edge_ct++;
        total_cost += wt;
        // cout<<u<<" "<<v<<endl;
    }
    
    if(added_edge_ct==n-1) cout<<total_cost<<"\n";
    else cout<<"IMPOSSIBLE"<<"\n";

    return 0;
}