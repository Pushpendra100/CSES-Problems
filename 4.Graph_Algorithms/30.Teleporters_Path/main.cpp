#include <bits/stdc++.h>
using namespace std;

// Semi Euler Graph / Euler Path - visit every edge once and starting and ending node will not be same


const int mxN = 1e5+10;
int n, m;
vector<vector<int>> g(mxN);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    return 0;
}