#include <bits/stdc++.h>
using namespace std;

// A matrix with some blocked cells and some cells free to move and on some free cells are monsters also.
// We need to find the optimal way to the exit which is through the boundary of the matrix

// multisource bfs - we put all source points in the queue in the starting only
/*
"thus d2 matrix always contains the min. distance a monster can reach in any (i, j) cell 
and for the person to escape he need to have less distance for the particular cell than monsters in the path he is moving 
that is person is able to reach that cell faster than all the monsters"


this is the pattern when taken xor with 2
-1 -3
0 2
1 3
2 0
3 1
4 6
5 7
6 4
7 5
8 10
*/

#define ll long long
#define ar array

const int mxN = 1e3, di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};
const char dc[4] = {'D', 'R', 'U', 'L'};
int n, m, si, sj, ti, tj, d1[mxN][mxN], d2[mxN][mxN], p1[mxN][mxN], p2[mxN][mxN];  //d- calculated distances and p - parents
string s[mxN];
bool vis[mxN][mxN];

bool e(int i, int j){
    return i>=0&&i<n&&j>=0&&j<m&&s[i][j]=='.'&&!vis[i][j];
}

void bfs(vector<ar<int, 2>> v1, int d[mxN][mxN], int p[mxN][mxN]){
    queue<ar<int, 2>> qu;
    memset(vis, 0, sizeof(vis));
    memset(d, 0x3f, sizeof(d1));
    for(ar<int, 2> a: v1){
        qu.push(a);
        vis[a[0]][a[1]] = 1;
        d[a[0]][a[1]] = 1;
    }
    while (qu.size())
    {
        ar<int, 2> u = qu.front();
        qu.pop();
        for(int k = 0; k<4; k++){
            int ni = u[0]+di[k], nj = u[1]+dj[k];
            if(!e(ni, nj)) continue;
            qu.push({ni, nj});
            vis[ni][nj] = 1;
            d[ni][nj]=d[u[0]][u[1]]+1;
            p[ni][nj] = k;
        }
    }
    
}

int main() {

    cin>>n>>m;
    vector<ar<int, 2>> v2;
    for(int i = 0; i<n; ++i){
        cin>>s[i];
        for (int j = 0; j <m; j++)
        {
            if(s[i][j]=='A')
                si = i, sj = j, s[i][j] = '.';
            if(s[i][j]=='M')
                v2.push_back({i, j}), s[i][j] = '.';
        }
    }

    bfs({{si, sj}}, d1, p1); // bfs for the person 
    bfs(v2, d2, p2); //for monster - multiple source bfs 
    int ti = -1, tj=-1;
    for(int i = 0; i< n; i++){
        // (i, 0), (i, m-1)
        if(d1[i][0] < d2[i][0])
            ti = i, tj = 0;
        if(d1[i][m-1]< d2[i][m-1])
            ti = i, tj = m-1;

    }
    for(int j = 0; j< m; j++){
        // (0, j), (n-1, j)
        if(d1[0][j]<d2[0][j])
            ti = 0, tj = j;
        if(d1[n-1][j]<d2[n-1][j])
            ti = n-1, tj = j;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j<m ; j++){
    //         cout<<dc[p1[i][j]];
    //     }
    //     cout<<endl;
    // }
    

    if(~ti){
        cout<<"YES\n";
        string t;
        while (ti^si||tj^sj)
        {
            t += dc[p1[ti][tj]];
            int dd = p1[ti][tj]^2;
            ti += di[dd];
            tj += dj[dd];
        }
        reverse(t.begin(), t.end());
        cout<<t.size()<<"\n";
        cout<<t;
    }else{
        cout<<"NO\n";
    }

    return 0;
}