#include <bits/stdc++.h>
using namespace std;

/*
What will be more optimal to sort - duration or deadline?

see, if we sort duration wise, then we are completing every task optimally and reaching at all tasks at the best time possible
but if we sort deadline wise, then we can complete one or two task optimally but other tasks will not be completely optimal as we have gained more days in the starting itself, thus it will kill more deadlines

Therefore, if we sort duration wise, we are taking minimum duration first thus we are saving more dealines from hitting and getting us more rewards

more deep explanation - https://www.youtube.com/watch?v=HBrtoN_gSgY

*/
#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i<n; i++){
        int a, b; cin>>a>>b;
        v[i] = {a, b};
    }    
    sort(v.begin(), v.end());

    ll t = 0, ans = 0;
    for(int i = 0; i<n; i++){
        t += v[i].first;
        ans +=v[i].second - t;
    }
    cout<<ans<<"\n";

    return 0;
}