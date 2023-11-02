#include <bits/stdc++.h>
using namespace std;

// This is counting the connected components

void dfs(int i, int j, vector<vector<char>> &map, int n, int m){

    if(i<0 || j<0) return;
    if(i>=n || j>=m) return;
    if(map[i][j]=='#') return;

    map[i][j] = '#';

    dfs(i-1, j, map, n, m);
    dfs(i+1, j, map, n, m);
    dfs(i, j-1, map, n, m);
    dfs(i, j+1, map, n, m);
}

int main() {
    int n, m;
    cin>>n>>m;
    vector<vector<char>> map(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {   
            char x;
            cin>>x;
            map[i].push_back(x);
        }
    }
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(map[i][j]=='.'){
                ct++;
                dfs(i,j,map,n,m);
            }
        }
        
    }
    cout<<ct<<"\n";
    

    return 0;
}