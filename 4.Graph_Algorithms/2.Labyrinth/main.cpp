#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e3+10, di[4]={1, 0, -1, 0}, dj[4]={0, 1, 0, -1};
const char dc[4] = {'D', 'R', 'U', 'L'};
int n, m, si, sj, ti, tj, d[mxN][mxN];
string s[mxN], p[mxN]; //string matrix


bool e(int i, int j){
    return i>=0 && i<n && j>=0 && j<m && s[i][j]=='.';
}


int main() {


    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        cin>>s[i];
        for (int j = 0; j < m; j++)
        {
            if(s[i][j]=='A'){
                si = i, sj = j;//, s[i][j] = '.';
            }
            if(s[i][j]=='B'){
                ti = i, tj = j, s[i][j] = '.';
            }

        }
        p[i] = string(m, 0);
    }

    queue<pair<int, int>> qu;
    qu.push({si, sj});
    while (qu.size())
    {
        pair<int,int> u = qu.front();
        int ci = u.first, cj = u.second;
        qu.pop();
        for (int k = 0; k < 4; k++)
        {
            int ni = ci+di[k], nj= cj+dj[k];
            if(!e(ni, nj)) continue;
            qu.push({ni, nj});
            s[ni][nj]='#';
            d[ni][nj]= k;
            p[ni][nj] = dc[k];
        }
    }
    if(p[ti][tj]){
        cout<<"YES\n";
        string t;// backtrack

        // xor of a number with 0 is the number itself
        while (ti^si || tj^sj)    // xor of same numbers is 0
        {
            t+=p[ti][tj];
            int dd = d[ti][tj]^2;
            ti+=di[dd];
            tj+=dj[dd];
        }
        

        reverse(t.begin(), t.end());
        cout<<t.size()<<"\n";
        cout<<t;
    }else{
        cout<<"NO\n";
    }
    
    

    return 0;
}