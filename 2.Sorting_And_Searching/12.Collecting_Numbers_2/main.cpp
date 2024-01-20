#include <bits/stdc++.h>
using namespace std;


// https://www.youtube.com/watch?v=W1Vf4gZznMs

/*
5 3
4 2 1 5 3
2 3
1 5
2 3

output
2
3
4


*/

int ans = 1;

void update(int u, int v, int val, vector<pair<int, int>> &a, vector<int> &pos){
    int n = a.size();
    if(pos[u] > pos[v]) swap(u, v);
    int i = pos[u], j = pos[v];

    // adjusting for i's left
    if(i>0 && a[i-1].second > a[i].second) ans += val;
    // adjusting for j's right
    if(j<n-1 && a[j].second > a[j+1].second) ans += val;

    if(i+1==j){
        // if adjacent
        if(a[i].second > a[j].second) ans+=val;
    }else{
        if(a[i].second > a[i+1].second) ans += val;
        if(a[j-1].second > a[j].second) ans += val;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin>>n>>k;
    vector<pair<int, int>> a(n);
    vector<int> pos(n+1);

    for(int i = 0; i<n; i++){
        cin>>a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    for(int i = 1; i<n; i++){
        if(a[i-1].second > a[i].second) ans++;
    }
    for(int i = 0; i<n; i++){
        pos[a[i].second] = i;//old to new index
    }

    while (k--)
    {
        int u, v; cin>>u>>v;
        u--, v--;
        update(u, v, -1, a, pos);

        // now swap and update correspondingly
        int i = pos[u], j = pos[v];
        swap(a[i].second, a[j].second);
        swap(pos[u], pos[v]);

        update(u, v, 1, a, pos);

        cout<<ans<<"\n";
    }
    

    return 0;
}