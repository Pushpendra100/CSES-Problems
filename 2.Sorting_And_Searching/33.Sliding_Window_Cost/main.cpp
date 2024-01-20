#include <bits/stdc++.h>
using namespace std;

// the minimum total cost of making all elements equal in an array, can be done by finding median, and adding the cost for every element

/*
in the previous question we have already find the sliding window median but now in this question we have additionally find the cost

8 3
2 4 3 5 8 1 2 1

for the first window 2 4 3

ls = (2, 0), (3, 2)
rs = (4, 1)

cost  = (size_of_ls*median - sum_of_elements_of_ls) +  (sum_of_elements_of_rs - size_of_rs*median )
      =  (2*3 - 5)  +   (4 - 1*3)
      =  2

thus every time we just need to update the sum_of_elements_of_ls and sum_of_elements_of_rs

*/

#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;
    set<pair<int , int>> leftSet, rightSet;
    vector<int> values(n);
    for(int i = 0; i<n; i++) cin>>values[i];
    if(k==1){
        // median will be the number itself, thus cost will be element - median, which will be 0
        for(int i = 0; i<n; i++) cout<<0<<" ";
        return 0;
    }
    if(k==2){
        // as min will be median thus median-median will not add to ans only other value - median will give our answer
        for(int i = 1; i<n; i++) cout<<max(values[i-1], values[i])-min(values[i-1], values[i])<<" ";
        return 0;
    }

    vector<pair<int, int>> st;
    for(int i = 0; i<k; i++) st.push_back({values[i], i});
    sort(st.begin(), st.end());

    ll ls = 0, rs = 0, ans = 0;
    
    for(int i = 0; i < (k+1)/2; i++) leftSet.insert(st[i]), ls += st[i].first;
    for(int i = (k+1)/2; i<k; i++) rightSet.insert(st[i]), rs += st[i].first;

    // cout<<leftSet.rbegin()->first<<" "; // this is our median
    ans = ( (leftSet.size()*1ll*(leftSet.rbegin()->first)) - ls ) + ( rs - (rightSet.size()*1ll*(leftSet.rbegin()->first)) );
    cout<<ans<<" ";

    for(int j = 1; j < n-k+1; j++){
        // erase the element
        // if(leftSet.count({values[j-1], j-1})) leftSet.erase({values[j-1], j-1});
        // else rightSet.erase({values[j-1], j-1});
        // this will take O(N)

        // erase the element
        if(make_pair(values[j-1], j-1) > *leftSet.rbegin()) rs-=values[j-1], rightSet.erase({values[j-1], j-1});
        else ls-=values[j-1], leftSet.erase({values[j-1], j-1});

        // adding the new element
        if(*(leftSet.rbegin()) < make_pair(values[j+k-1], j+k-1)) rs+=values[j+k-1], rightSet.insert({values[j+k-1], j+k-1});
        else ls+=values[j+k-1], leftSet.insert({values[j+k-1], j+k-1});

        // making the size of sets in correct order 
        // left set is smaller than required
        while (leftSet.size()<(k+1)/2)
        {
            pair<int, int> z = (*rightSet.begin());
            rs -= z.first, rightSet.erase(rightSet.begin());
            ls += z.first, leftSet.insert(z);
            
        }
        // left set is greater than required
        while(leftSet.size()>(k+1)/2){
            pair<int, int> z = (*leftSet.rbegin());
            ls -= z.first, leftSet.erase(--leftSet.end());    // we can't use reverse iterator inside the erase function
            rs += z.first, rightSet.insert(z);
        }

        // print the answer
        // cout<<leftSet.rbegin()->first<<" ";  this is our median
        ans = ( (leftSet.size()*1ll*(leftSet.rbegin()->first)) - ls ) + ( rs - (rightSet.size()*1ll*(leftSet.rbegin()->first)) );
        cout<<ans<<" ";
    }

    return 0;
}