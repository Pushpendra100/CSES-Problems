#include <bits/stdc++.h>
using namespace std;


// This solution is actually not working for one test case of the cses - testcase 17
// something breaking in priority queue - don't know why :(
// giving time limit exceeded


// https://www.youtube.com/watch?v=9HMawd5jn9A

// we are given unweighted, directed and acyclic graph
// and we need to find SSLP( single source longest path )

// Dijkstra 

/*
Q. Can we convert it into a SSSP from SSLP?
- We can assign weight to each edge as -1 and this becomes an SSSP

Q. Then question is does dijkstra will work fine

Dijkstra is a greedy algo
Dijkstra assumes monotonicity. Monotonocity means a function is either non-decreasing or non-increasing

if one edge is A - (+500) - B and then next edge is B - (-480) - C then this is called polytonic because first +500 thus value increases and then decreases due to -480  and here dijkstra fails
But in our problem statement this is negative monotonic, i.e. all edges are -ve and distance is constantly decreasing

i.e. as long as we are constantly positive we are ok and same for negative
In a negative monotonic sceanario, our Dijkstras will greedily seek the path with the most negativity

but we need to care about negative cycles
Note: If there are are negative cycles; there could be issues. But our problem statement says no directed cycle
    exist. Hence there would be no negative cycle


Q. How to retrieve longest path?
- While relaxing edge with  Dijkstras record parents!
- if edge uv relaxes vertex v, then u is the parent/relaxant of v
*/
#define endl "\n"
#define int long long int

const int INF = 1e9;
int n, m;
vector<vector<pair<int, int>>> g;
vector<int> dist, par;



void dij(){
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq; 

    // set<pair<int, int>> pq;

    pq.push({0, 1});
    // pq.insert({0, 1});
    dist[1] = 0;
    par[1] = -1;

    while (!pq.empty())
    {   
        int u = pq.top().second;
        // int u = pq.begin()->second;
        int d = pq.top().first;
        // int d = pq.begin()->first;
        pq.pop();
        // pq.erase(pq.begin());

        if(dist[u] < d) continue;

        for(auto e: g[u]){
            int v = e.first;
            int c = e.second;
            if(dist[v] > dist[u] + c){
                dist[v] = dist[u] + c;
                pq.push({dist[v], v});
                // pq.insert({dist[v], v});
                par[v] = u;
            }
        }
    }
}




int32_t main() {

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin>>n>>m;
    g.resize(n+1);
    dist.resize(n+1);
    par.resize(n+1);
    for(int i = 0; i<m;  i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back({b, -1});
    }
    for (int i = 2; i <=n; i++)
    {
        par[i] = -1;
    }
    
    dij();

    if(dist[n] == 0){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    //path retrieval
    cout<<1+dist[n]*(-1)<<endl;
    vector<int> ans;
    int temp = n;
    while (temp != -1)
    {
        ans.push_back(temp);
        temp = par[temp];
    }
    reverse(ans.begin(), ans.end()); 
    for(auto u:ans){
        cout<<u<<" ";   
    }

    

    return 0;
}