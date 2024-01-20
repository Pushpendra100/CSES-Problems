#include <bits/stdc++.h>
using namespace std;

#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    ll ans = -1e18, msf = -1e18;
    for(int i = 0; i<n; i++){
        int a; cin>>a;
        msf = max(0LL + a, msf+a);
        ans = max(ans, msf);
    }
    cout<<ans;
    return 0;
}