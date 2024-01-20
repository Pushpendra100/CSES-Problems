#include <bits/stdc++.h>
using namespace std;

#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    sort(a.begin(), a.end());
    ll x = a[n/2], ans = 0;
    for(int i = 0; i<n; i++) ans += abs(a[i]-x);
    cout<<ans<<"\n";

    return 0;
}