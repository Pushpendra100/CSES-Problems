#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 2e5;
int n, a[mxN]; 


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    ll s = 0, ans = 0;
    map<ll, int> mp;
    mp[0]++;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        s=(s+a[i]%n + n) % n; // elements can be negative also thus we added n
        ans += mp[s];
        mp[s]++;
    }
    cout<<ans<<"\n";

    return 0;
}