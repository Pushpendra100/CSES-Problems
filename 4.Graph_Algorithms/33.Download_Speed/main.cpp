#include <bits/stdc++.h>
using namespace std;

// https://cp-algorithms.com/graph/edmonds_karp.html

/*
Edmonds karp algo for Maximum flow
Time complexity of edmonds karp is O(V*E^2)
*/

#define ll long long 

int n, m;
const ll INF = 1e18+1;
const int mxN = 510;
ll capacity[mxN][mxN]; //stores the residual capacity of the network
vector<int> adj[mxN];


ll bfs(int s, int t, vector<int> &parent){
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, ll>> q;
    q.push({s, INF});
    while (!q.empty())
    {
        int cur = q.front().first;
        ll flow = q.front().second;
        q.pop();
        for(int next: adj[cur]){
            if(parent[next]==-1 && capacity[cur][next]){
                parent[next] = cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if(next==t){
                    return new_flow;
                }
                q.push({next, new_flow});
            }
        }
    }
    
    return 0;
}   

ll maxflow(int s, int t){
    ll flow = 0;
    vector<int> parent(n+1);
    ll new_flow;
    while((new_flow = bfs(s, t, parent))){
        flow += new_flow;
        int cur = t;
        while (cur != s)
        {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        capacity[a][b] += c;
    }
    ll mf = maxflow(1, n);
    cout<<mf<<endl;

    // for(int i = 1; i<=n ;i++){
    //     for(int j=1; j<=n; j++){
    //         cout<<capacity[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    return 0;
}