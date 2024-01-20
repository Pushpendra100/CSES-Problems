#include <bits/stdc++.h>
using namespace std;

/*
This is interval schedule problem

we will sort according to the ending - we need to take shows which are ending first
- by sorting according to the end, we will get the best movie which will be ending first at that moment than others which are available
*/

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        int start, end; cin>>start>>end;
        a[i] = {end, start};
    }
    
    sort(a.begin(), a.end());

    int ans = 0, l = 0;
    for(int i = 0; i<n; i++){
        if(a[i].second >= l){
            ans++;  
            l = a[i].first;
        }
    }

    cout<<ans<<"\n";

    return 0;
}