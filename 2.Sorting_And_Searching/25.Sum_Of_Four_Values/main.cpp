#include <bits/stdc++.h>
using namespace std;

// Hashmaps

// time complexity of this implementation = O(n^2)

// https://usaco.guide/problems/cses-1642-sum-of-four-values/solution
/*
Since we are looking for four numbers a + b + c + d = x, we can store all the values that we can achieve using a pair of numbers, and 
the indices for both numbers in the pair using a map. Then, the problem is reduced to finding two numbers a and b that sum up to a mapped value such that no index is repeated.

We can easily achieve this in O(N^2) by looping through all unique pairs of numbers, checking whether or not the hashmap contains a value corresponding to x-a-b, where a and b are the two numbers being checked.
We can then add any previously visited pair in order to make sure none of our indices overlap.
*/

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x; cin>>n>>x;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    unordered_map<int, pair<int, int>> mp;

    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            int idx = x - a[i] - a[j];
            if(mp.find(idx)!=mp.end()){
                cout<<i+1<<" "<<j+1<<" "<<mp[idx].first + 1<<" "<<mp[idx].second + 1;
                return 0;   
            }
        }
        for(int j = 0; j<i; j++){
            mp[a[i]+a[j]] = {i, j};
        }
    }
    cout<<"IMPOSSIBLE\n";

    return 0;
}