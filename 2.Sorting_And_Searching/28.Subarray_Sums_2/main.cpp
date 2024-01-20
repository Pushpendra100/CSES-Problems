#include <bits/stdc++.h>
using namespace std;


// Same as previous question
// Finding the count of subarrays in a given array whose sum is x

#define ll long long

const int mxN = 2e5;
int n;
ll x, a[mxN];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>x;
    ll s = 0, ans = 0;
    map<ll, int> mp;
    mp[0]++;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        s+=a[i];  // maintaining cummulative sum in a variable
        // we know mp[s] is possible as we are iterating but we need to check that mp[s-x] is possible or not
        // if possible then it adds 1 to our answer, and it means that their exist some subarray whose sum is x
        ans += mp[s-x];
        mp[s]++; // it tells what cummulative prefix sums are available
    }
    cout<<ans;

    return 0;
}