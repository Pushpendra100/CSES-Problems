#include <bits/stdc++.h>
using namespace std;

/*
all possible permutations we have to find out

for aaabc
     = 5!/3!
*/

const int mxN = 1e6+1;
const int M = 1e9+7;
int fact[mxN];
int hsh[26];

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
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fact[0] = 1;
    for(int i = 1; i<=mxN; i++){
        fact[i] = (fact[i-1]*1LL*i)%M;
    }
    string s;
    cin>>s;
    for (size_t i = 0; i < s.size(); i++)
    {
        hsh[s[i]-'a']++;
    }
    int ans = fact[s.size()];
    for (size_t i = 0; i < 26; i++)
    {
        if(hsh[i]>1){
            ans = (ans * 1LL * binExp(fact[hsh[i]], M-2, M)) % M;
        }
    }
    cout<<ans<<"\n";


    return 0;
}