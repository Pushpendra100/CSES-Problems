#include <bits/stdc++.h>
using namespace std;

// video explanation great one = https://www.youtube.com/watch?v=2Epc8xZObIc

/*
Dijkstra is a greedy algorithm and Bellman ford is a dp algorithm
and we need n-1 times cycles in Bellman ford, because if there are no cycles in the graph then all the nodes are connected in straight line and for them n-1 edges are there
and they need n-1 times propagation of values (distance) from source to last vertex


Thus we need to do n-1 times relaxation for all edges
and if no negative cycle then this will be the answer


Bellman ford returns SSSP(single source shortest path) in V*E operations when no negative cycles
When bellman ford has negative cycle - bellman ford resolves neg cycles in 2*V*E operations with neg cycles


Use BFS when no weights.
Use Dijikstra when positive weights.
Use Bellman ford when Negative weights and negative cycles
*/


/*
Because we are going to reverse the weights to find the maximum path, 
and thus we will check for positive weight cycles instead of negative weight cycles
and if our positive weight cycle is affecting the answer for nth node, then we will return -1 
otherwise we will return the distance 
*/

#define ll long long


const ll INF = 1e17;
const ll NINF = INF*(-1);

struct triplet{
    int first;
    int second;
    int third;
};

int n, m;
vector<triplet> edges;
vector<ll> dist;


void bellman_ford(){

    // propagation phase
    for(int i = 1; i<n; i++){
        for(auto e: edges){
            int u = e.first;
            int v = e.second;
            int d = e.third;

            if(dist[u] == INF) continue;
            dist[v] = min(dist[v], d+dist[u]); // if relaxation possible then do it
            dist[v] = max(dist[v], NINF); //if values goes below NINF then this line will reset it to NINF and thus it creates a floor
        }
    }
    //negative cycle resolution phase
    // after this running n-1 times again we will have our SSSP
    for(int i = 1; i<n; i++){
        for(auto e: edges){
            int u = e.first;
            int v = e.second;
            int d = e.third;

            if(dist[u] == INF) continue;
            dist[v] = max(dist[v], NINF); // again reset
            if(dist[u]+d<dist[v]){ // upto here we have already done n-1 cycles and if still this if statement is true then it means negative cycle is present
                dist[v] = NINF;
            }
        }
    }
}


int main(){
    cin>>n>>m;
    dist.resize(n+1);
    edges.resize(m);
    for(int i = 0; i<m; i++){
        struct triplet a;
        cin>>a.first>>a.second>>a.third;   
        a.third *= -1;
        edges[i] = a;
    }
    for(int i = 2; i<=n; i++){
        dist[i] = INF;
    }
    bellman_ford();
    cout<<(dist[n]==NINF?-1:(-dist[n]))<<endl;
}

