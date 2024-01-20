#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


// https://www.youtube.com/watch?v=KnsDFCcBJbY

// the idea is same as preivous one but now we need to count things
/*
this is how we were sorting the ranges in our previous question
    // this example is different from what is given in the question
1    6
 2  5
 2 4
  3  6
   4   8

1st solution - using ordered set
    we are going to store the last right border of every range in the ordered set but we know as set can't store duplicate elements
    we will store pair thus to store their index and it will make them unique too

for contained (i.e. this current range is contained in how many other ranges)
    1    6
     2  5
     2 4
      3  6
       4     8

    we need to store all right values in sorted order but for same right value we need to store first that value whose index is more than the other
    thus we will store the index * -1

    we are going to use method order-of-key

    let's start iteration 
    ordered_set = (6, 0)

    size_of_set - order_of_key  - 1 ===> this will give the no. of elements after this element in set
    here 1 - 0 - 1 = 0

    now, ordered_set = (5, 1), (6, 0);

    2 - 0 - 1 = 1 i.e. this current range is contained in exactly one range

    now, ordered_set = (4, 2), (5, 1), (6, 0)
    3 - 0 - 1 = 2 i.e.this current range is contained in exactly two ranges

    now, ordered_set = (4, 2), (5, 1), (6, 0), (6, 2)
    but we actually want for equal value we need to have the greater index before, thus we will give -ve sign to all indexes
    ordered_set = (4, -2), (5, -1), (6, -2), (6, 0)
    4 - 2 - 1 = 1, i.e. 1 range contains this current range

    ...... this is how we can find contained


for contains (i.e. this current range is containing how many other ranges)
    1    6
     2  5
     2 4
      3  6
       4     8
    
    for finding the contains we need to go from down to up so that we can know how manyranges does the current range store
    from the sets we need to get elements which are smaller the current value and for the same value the index should be greater than the current index

    thus all the elements that will be left to the current index will be our answer, and since we are going to store index * -1 this way, for same value larger index will be also be left for two same value.



2nd solution - segment tree/fenwick tree
https://www.youtube.com/watch?v=Lyi7N_cB55w

*/


#define ln "\n"
#define ll long long

struct range{
    int l, r, index;
    bool operator < (const range &other) const {
        if(l==other.l) return r > other.r;
        return l < other.l;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    vector<range> ranges(n);
    vector<int> contained(n), contains(n);
    ordered_set<pair<int, int>> rightBoundaries;
    for(int i = 0; i<n; i++){
        cin>>ranges[i].l>>ranges[i].r;
        ranges[i].index = i;
    }
    sort(ranges.begin(), ranges.end());     

    for(int i = 0; i<n; i++){
        rightBoundaries.insert({ranges[i].r, -1*i});
        contained[ranges[i].index] = rightBoundaries.size() - rightBoundaries.order_of_key({ranges[i].r, -1*i}) - 1;
    }
    rightBoundaries.clear();
    for(int i = n-1; i >= 0; i--){
        rightBoundaries.insert({ranges[i].r, -1*i});
        contains[ranges[i].index] = rightBoundaries.order_of_key({ranges[i].r, -1*i});
    }

    for(int i = 0; i < n; i++) cout<<contains[i]<<" ";
    cout<<ln;
    for(int i = 0; i < n; i++) cout<<contained[i]<<" ";
    cout<<ln;

    return 0;
}