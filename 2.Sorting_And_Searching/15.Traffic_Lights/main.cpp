#include <bits/stdc++.h>
using namespace std;

// 0 1 2 3 4 5 6 7 8
//     t t     t

const int mxN = 2e5;
int x, n, p[mxN];
map<int, int> mp; // map to store know which distances are available and map will provide in sorted fashion

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>x>>n;
    set<int> s; // set to know at which points we have lamp
    s.insert(0); s.insert(x);
    mp[x] = 1;
    for (int i = 0; i < n; i++)
    {
        cin>>p[i];
        auto it = s.lower_bound(p[i]);
        int r = *it;
        --it;
        int l = *it;
        --mp[r-l];
        if(!mp[r-l]) mp.erase(r-l);
        s.insert(p[i]);
        ++mp[r-p[i]];
        ++mp[p[i]-l];
        cout<<((--mp.end())->first)<<" ";
    }
    
    

    return 0;
}