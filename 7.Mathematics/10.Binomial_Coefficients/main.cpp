#include <bits/stdc++.h>
using namespace std;

// https://cp-algorithms.com/combinatorics/binomial-coefficients.html
// study combinatorics chapter from cph

// Computing binomial coefficients modulo m 
//      - Binomial Coefficient modulo large prime
//      - Binomial Coefficient modulo prime power
//      - Binomial coefficient modulo an arbitrary number
//      - Binomial coefficient for large n and small modulo

// Here we are going to use - Binomial Coefficient modulo large prime
/*
    formula for binomial coeff is (n k) = n!/k!(n-k)!
    so if we want to compute it modulo some prime, m>n we get

        (n k) = n!.(k!)^-1.((n-k)!)^-1 mod m


    First we compute all factorials modulo m up to MAXN! in O(MAXN) time
    fatorial[0] = 1;
    for(int i = 1; i<= MAXN; i++){
        factorial[i] = factorial[i-1] * i % m;
    }

    And afterwards we can compute the binomial coefficient in O(logm) time
    long long binomial_coefficient(int n, int k){
        return factorial[n] * inverse(factorial[k] * factorial[n-k] % m) % m;
    }

    We even can compute the binomial coefficient in O(1) time if we precompute the inverses of all factorials in O(MAXN logm)

    MMI of a is a^-1 % M
    a^-1 % M = binExp(a, M-2, M)    when M is prime

*/

const int mxN = 1e5;
const int mxA = 1e6+1; 
const int M = 1e9+7;
int factorial[mxA];


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
    
    factorial[0] = 1;
    for(int i = 1; i<= mxA; i++){
        factorial[i] = (factorial[i-1] * 1LL * i) % M;
    }

    while (n--)
    {
        int x, y;
        cin>>x>>y;
        int ans = factorial[x];
        int den = (factorial[x-y]*1LL*factorial[y]) % M;
        ans = (ans * 1LL * binExp(den, M-2, M)) % M;
        cout<<ans<<"\n";
    }
    

    return 0;
}