#include <bits/stdc++.h>
using namespace std;

/*
derangement refers to the permutation consisting of elements of a set in which the elements don’t exist in their respective usual positions.

Dearrangement
 = n!(1 - 1/1! + 1/2! - 1/3! ...... 1/n!);

*/

const int mxN = 1e6+10;
const int M = 1e9+7;
int fact[mxN];

int binExp(int a, int b, int m){
    int result = 1;
    while (b>0)
    {
        if(b&1){
            result = (result * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b>>=1;
    }
    return result;
}// O(logM)

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    fact[0] = 1;
    for(int i = 1; i<mxN; i++){
        fact[i] = (fact[i-1]*1LL*i) % M;
    }
    int part = 1;
    for(int i = 1;i<=n; i++){
        if(i&1) part = (part - binExp(fact[i], M-2, M) + M)%M;
        else part = (part + binExp(fact[i], M-2, M)) % M;
    }
    int ans = (fact[n]*1LL*(part))%M;
    cout<<ans<<"\n";
    return 0;
}