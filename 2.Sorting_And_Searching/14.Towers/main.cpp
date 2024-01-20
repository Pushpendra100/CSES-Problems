#include <bits/stdc++.h>
using namespace std;


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    vector<int> v; // we are storing each towers top element
    for(int i = 0; i<n; i++){
        int a; cin>>a;
        int p = upper_bound(v.begin(), v.end(), a) - v.begin();
        if(p<v.size()){
            v[p] = a;
        }else v.push_back(a);
    }
    cout<<v.size()<<"\n";

    return 0;
}