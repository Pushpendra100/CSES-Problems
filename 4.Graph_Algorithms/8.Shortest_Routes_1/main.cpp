#include <bits/stdc++.h>
using namespace std;

/*
Dijkstra Algorithm
You are given a directed or undirected weighted graph with n vertices and m edges. The weights of all edges are non-negative. You are also given a starting vertex s . This article discusses finding the lengths of the shortest paths from a starting vertex  
s  to all other vertices, and output the shortest paths themselves.
This problem is also called single-source shortest paths problem.
*/

#define ll long long

int n, m;
const int N = 1e5+10;
const ll INF = 1e18;

vector<pair<int, int>> g[N];
vector<int> vis(N, 0);
vector<ll> dist(N, INF);

void dijkstra(int source){
    set<pair<ll, int>> st;
    // wt. is first in st pair to sort according to wt
    
    st.insert({0, source});
    dist[source] = 0;

    while (st.size())
    {
        auto node = *st.begin();
        int v = node.second;
        ll v_dist = node.first;
        // cout<<v<<" "<<v_dist<<" "<<vis[v]<<endl;
        st.erase(st.begin());
        if(vis[v]) continue;
        vis[v] = 1;   // when node comes itself then no more short distances can be found for v thus we put vis[v] = 1, as in the set nodes which are less far comes before v and already make it shortest if possible

        for(auto child :g[v]){
            int child_v = child.first;
            int wt = child.second;

            if(v_dist+wt < dist[child_v]){
                dist[child_v] = v_dist + wt;        
                st.insert({dist[child_v], child_v});
            }
            // both are correct above and this below if statement
            // if(dist[v]+wt < dist[child_v]){  //if visited node is coming as a child and it is possible to reduce its distance then we can do this here
            //     dist[child_v] = dist[v] + wt;   
            //     st.insert({dist[child_v], child_v}); 
            // }


        }
    }

}

int main() {

    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin>>x>>y>>w;
        g[x].push_back({y, w});
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++)
    {
        cout<<dist[i]<<endl;
    }
    

    return 0;
}