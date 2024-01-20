#include <bits/stdc++.h>
using namespace std;

// We need to count subarrays which have at most k distinct values


// https://www.youtube.com/watch?v=R4Gq_SMc8Uo
/*
input
5 2
1 2 3 1 1

output
10


1
1 2
2
2 3 moving further forward will give 3 distinct values thus we move our l to l+1
3
3 1
3 1 1
1 
1 1
1

## brute force
we will maintain a set of elements, as size of set = no. of distinct elements
for(i = 0; i<n; i++){
    for(j = i + 1; j<n; j++){
        // i will maintain left boundary while j will maintain the right boundary
        set<int> st;
        for(x = i; x<j; x++) st.insert(a[x]);  //logn
        if(st.size()<=k) ans++;
    }
}
this time complexity is O(N^3logN);


## Actual approach
instead of set we need to have data structure which can store the no. of occurences of the element as well.
Thus we are going to use map. size of map will also tell us the number of distinct values that we have.

We are going to use a kind of a two pointers method both pointers are going to move in the same direction

1 2 1 3 1       map = {(1:1)}
i
j

1 2 1 3 1       map = {(1:1), (2:1)}
i
  j

1 2 1 3 1       map = {(1:2), (2:1)}
i
    j

1 2 1 3 1       map = {(1:2), (2:1), (3:1)}
i
      j
now here the size of map is greater than k, i.e. 2 in this case
and we will add j-i in our count = 3
as 1 | 2 | 1 | 3 we have got 3 subarrays
and now since we have crossed k we are going to move i by +1 and decrement mp[i]--;


1 2 1 3 1       map = {(1:1), (2:1), (3:1)}
  i
      j
since again we have map.size()>k we will add j-i in our count
and we have still 3 elements in the map thus we will again move i to i+1;


1 2 1 3 1       map = {(1:1), (3:1)}
    i
      j
now since map size is 2 we will increase j until it crosses k
 

 1 2 1 3 1 4 5 6       map = {(1:2), (3:1), (4:1)} 
     i
           j
again we have size of map greater than k
thus we will add j-i = 3 in our count
and again move i to i+1;


this is how we will be going until i reaches n-1 and j reaches n
*/


/* 
if we have n distinct elements in a array then it has n*(n-1)/2 subarrays

*/

#define ll long long

const int mxN = 2e5;
int n, k, a[mxN];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    for(int i= 0; i<n; i++) cin>>a[i];
    ll ans = 0;
    map<int, int> occurences;
    for(int i = 0, j= 0; i<n; i++){
        while(j<n && ((int)occurences.size()<k || occurences.count(a[j])>0)){ //occurences.count(a[j])>0) this checks that current j, this value of j is already present in our map thus we can go for taking next j
            occurences[a[j]]++;
            j++;
        }
        // cout<<i<<" "<<j<<" "<<j-i<<endl;
        ans += j-i;
        occurences[a[i]]--;
        if(occurences[a[i]]==0) occurences.erase(a[i]);
    }
    cout<<ans<<"\n";

    return 0;
}