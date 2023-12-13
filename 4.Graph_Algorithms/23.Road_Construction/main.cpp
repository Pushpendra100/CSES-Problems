#include <bits/stdc++.h>
using namespace std;

// DSU - Disjoint Set Union

const int N = 1e5+10;
int parent[N];
int siz[N];

void make(int v){
    parent[v] = v;
    siz[v] = 1;
}

int find(int v){
    if(v==parent[v]) return v;
    return parent[v] = find(parent[v]); // path compression
}

int Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(siz[a]<siz[b]) swap(a,b);  // union by size
        parent[b] = a;
        siz[a] += siz[b];
    }
    return siz[a];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin>>a>>b;
        edges.push_back({a, b});
    }
    for(int i = 1; i<=n; i++) make(i);
    int comp_ct = n, mx_comp_sz = 1;
    for(auto edge: edges){
        auto [u, v] = edge;
        if(find(u)==find(v)) cout<<comp_ct<<" "<<mx_comp_sz<<"\n";
        else{
            int new_size = Union(u, v);
            --comp_ct;
            mx_comp_sz = max(mx_comp_sz, new_size);
            cout<<comp_ct<<" "<<mx_comp_sz<<"\n";
        }
    }

    return 0;
}