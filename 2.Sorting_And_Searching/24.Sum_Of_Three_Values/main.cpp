#include <bits/stdc++.h>
using namespace std;

// Extension of the two sum problem
// thus we need to use two pointers with some modification

// time complexity = O(n^2)

/*
    First we will sort the array.
    Then we will loop through all possible values for the third pointer and check if all three pointers add up to the target amount, x, while having distinct positions.
    We can maintain the original positions of all values by storing the pairs {a[i], i};
*/

#define ll long long


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x; cin>>n>>x;
    pair<int, int> a[n];
    for(int i = 0; i<n; i++){
        int e; cin>>e;
        a[i] = {e, i};
    }
    sort(a, a+n);
    for(int i = 0; i<n; i++){
        ll x2 = x-a[i].first; //fixing one element
        // now we will do two pointers
        for(int j = i+1, k=n-1; j<k; j++){
            while(j<k && a[j].first+a[k].first>x2) --k;
            if(j<k && a[j].first+a[k].first==x2){
                cout<<a[i].second+1<<" "<<a[j].second+1<<" "<<a[k].second+1;
                return 0;
            }
        }
    }// O(N^2)
    cout<<"IMPOSSIBLE\n";

    return 0;
}