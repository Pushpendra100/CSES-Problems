#include <bits/stdc++.h>
using namespace std;

// best video explanation - https://www.youtube.com/watch?v=GZtZXhir7Wg

/*
Greedy approach
Dijkstra
*/

#define int long long int
#define endl "\n"

const int INF = 9e17;
int n, m;

vector<vector<pair<int, int>>> g;
vector<int> dist;  //full price vector
vector<int> disc;  // discounted price vector
// our ans is disc[n]

void dij(){
    // priority queue is just like multiset 
    priority_queue<
        pair<int, pair<int, int>>,  //element type
        vector<pair<int, pair<int, int>>>,  //container type
        greater<pair<int, pair<int, int>>>  //comparison function - this greater function makes it min heap i.e. sort in ascending order
    > pq;
    // pair<int, pair<int, int>>
    //      cost,    dest, flag
    // so we will be sorting on basis of cost

    for(int i = 2; i<=n; i++){
        dist[i] = INF;
        disc[i] = INF; 
    }

    // 0 -> coupon is not used
    // 1 -> coupon is used

    pq.push({0, {1, 0}}); // this is our starting point

    // retrieving from pq, rejecting if bad
    while(!pq.empty()){
        int d = pq.top().first;         //cost of package
        int u = pq.top().second.first;  // destination
        int f = pq.top().second.second; //flag
        pq.pop();

        if(f==1){ // i.e. coupon is used
            if(disc[u] < d) continue; // if d is not offering better than what we have, then we are continuing
        }
        if(f==0){ // without coupon
            if(dist[u]<d) continue; 
        }
        // now we know the deal which is coming is better for us
        // now we need to avail this deal 
        for(auto e: g[u]){
            int v = e.first, c = e.second;
            if(f==0){
                //either we can use flag or not

                // not using coupon from u to v
                if(dist[v]>c+d){
                    dist[v] = c + d; //relaxation
                    pq.push({dist[v], {v, 0}}); // push in the heap, i.e. heapify
                }
                // using coupon from u to v
                if(disc[v]> d+c/2){
                    disc[v] = d+c/2;
                    pq.push({disc[v], {v, 1}});
                }
            }
            // coupon has been already availed
            if(f==1){
                if(disc[v]> d+c){
                    disc[v] = d + c;
                    pq.push({disc[v], {v, 1}});
                }
            }
        }
    }
    cout<<disc[n]<<endl;

}

int32_t main() {

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin>>n>>m;
    g.resize(n+1);
    dist.resize(n+1);
    disc.resize(n+1);
    for(int i = 0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        g[a].push_back({b, c});
    }
    dij();
    // for (int i = 1; i <=n; i++)
    // {
    //     cout<<disc[i]<<" ";
    // }
    // cout<<endl;
    // for (int i = 1; i <=n; i++)
    // {
    //     cout<<dist[i]<<" ";
    // }
    
    return 0;
}