#include <bits/stdc++.h>
using namespace std;

// good blog for two pointer technique and its variation =  https://codeforces.com/blog/entry/77127
// Finding a pair in a array whose sum is x

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x; cin>>n>>x;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++)
    {
        int x; cin>>x;
        a[i] = {x, i};
    }
    
    sort(a.begin(), a.end());
    int l = 0, r = n-1;
    while (l<r)
    {
        if(a[l].first +a[r].first ==x) break;
        else if(a[l].first + a[r].first<x) l++;
        else r--;
    }
    if(l<r) cout<<a[l].second+1<<" "<<a[r].second+1<<"\n";
    else cout<<"IMPOSSIBLE"<<"\n";


    return 0;
}