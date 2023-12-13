#include <bits/stdc++.h>
using namespace std;

/*
Floyd Warshall Algorithm: All Pair Shortest Path 
this algorithm 
- can handle negative weights
- can't handle negative weighted cycle


d[i][j] = d[i][k] + d[k][j]

*/

#define ll long long

const int N = 510;
const ll INF = 1e18+10;

ll dist[N][N];



int main() {

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    int n, m, q;
    cin>>n>>m>>q;
    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin>>x>>y>>wt;
        if(dist[x][y]>wt){
            dist[x][y] = wt;
            dist[y][x] = wt;
        }
    }

    //Floyd Warshall loop
    for(int k = 1; k<=n; k++){ // k is level
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    // TC:- O(n^3)

    while (q--)
    {
        int a, b;
        cin>>a>>b;
        cout<<(dist[a][b]==INF?-1:dist[a][b])<<"\n";
    }
    

    // for (int i = 1; i <=n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {   
    //         if(dist[i][j] == INF){
    //             cout<<"I ";
    //         }else{
    //             cout<<dist[i][j]<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }
// 0 5 8 I 
// 5 0 3 I 
// 8 3 0 I 
// I I I 0 
    

    return 0;
}