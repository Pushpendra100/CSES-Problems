#include <bits/stdc++.h>
using namespace std;

// https://usaco.guide/problems/cses-1644-max-subarray-sum-ii/solution

// this is like sliding window maximum
// we can observe that we will be performing sum range queries for our subarray
// therefore, we should construct a prefix sum array to perform these queries


/*
Notice that we are trying to maximise pfx[i] - pfx[j].
Since j is guaranteed to be within the window [i-b, i], we can create a sliding window of size b, and compute max a<=i<=b(pfx[i]-pfx[j])
*/


#define ll long long

int n, a, b;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>a>>b;
    vector<ll> pfx(n+1);
    for(int i = 1; i<=n; i++){
        int a; cin>>a;
        pfx[i] = a + pfx[i-1];
    }

    ll ans = -1e18;
    multiset<ll> ms; 
    // we can keep a sliding window of size b, then find the lowest pfx[j] using multiset
    for(int i = a; i<=n; i++){
        if(i>b) ms.erase(ms.find(pfx[i-b-1])); //erase the element if size > b
        ms.insert(pfx[i-a]);    
        ans = max(ans, pfx[i]-*ms.begin()); // we want to minimize ms.begin() aka pfx[j]
        // cout<<ans<<" ";
    }

    cout<<ans<<"\n";

    /*
    ms = pfx[0]
    ans = max(-1e18, -1) = -1;

    ms = -1, 0
    ans = max(-1, 2-(-1)) = 3;

    ms = -1, 2
    ans = max(3, 0-(-1)) = 3;

    ms = 0, 2
    ans = max(3, 5 - 0) = 5;

    .. and this goes on
    */

    return 0;
}