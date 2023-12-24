#include <bits/stdc++.h>
using namespace std;

// Grundy's Game

// see book (competitive programming handbook) page-240
// https://codeforces.com/blog/entry/82103
/*
We find the Sprague-Grundy values corresponding to the Grundy’s game. This can be easily done by dynamic programming, as we find the mex of all the state reachable from that state.
 Also we note that for larger values of n (n≥2000), its Sprague-Grundy value is never 0. (I don’t have a proof for this, maybe someone can let me know in the comments.)
*/
// for further - You can read about Sprague-Grundy theorem here
// https://cp-algorithms.com/game_theory/sprague-grundy-nim.html

#define ll long long

ll mex(vector<ll> v){
    set<ll> s;
    for (size_t i = 0; i < v.size(); i++){
        s.insert(v[i]);
    }
    for(int i = 0; i<1000001; i++){
        if(s.count(i)==0) {
            return (ll)i;
        }
    }
    return 0; // just to complete function
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll limit = 2000;
    ll dp[limit];
    dp[0] = dp[1] = dp[2] = 0;
    for(int i = 3; i<limit; i++){
        vector<ll> v;
        for(int j = 1; 2*j<i; j++){
            v.push_back(dp[j]^dp[i-j]);
        }
        dp[i] = mex(v);
    }

    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        if(n>=limit) cout<<"first";
        else if(dp[n]==0) cout<<"second";
        else cout<<"first";
        cout<<"\n";
    }
    

    return 0;
}