#include <bits/stdc++.h>
using namespace std;

// https://usaco.guide/problems/cses-1076-sliding-median/solution
// https://www.youtube.com/watch?v=UGs_kQxJNPk
/*
It can be solved in three ways:-
    1. Maintaining two multisets = O(NlogN) 
    2. Fenwick Tree = O(N(logN)^2) 
    3. Order Statistic Tree = O(NlogN) 
*/

/*

Solving using multisets

8 3
2 4 3 5 8 1 2 1

(2, 0), (4, 1), (3, 2)

(2, 0), (3, 2), (4, 1)
--------------- -------
    left set     right set

our median will be part of our low/left set

(2,0)
(3,2)
left set

(4, 1)
right set

and thus for median we will print the last element of left set =  *low.rbegin();

And now we are going to shift the window to next element
we remove the element (2,0) from the set(it can be any of the sets thus we will find it and erase it) and add the new element (5, 3) in the set

now for adding new element in the set, we will compare it with the *low.rbegin(); if it is smaller or equal then we 
will put this in the left set if greater than that then we will put it in the right set

(3, 2) = Left set
(4, 1), (5, 2) = Right set

one thing to observe is that for k = 3, we can say that left set should be of size 2 while right set should be of size 1
thus currently now since the size of sets is not balanced, we will keep putting smallest elements from right set to the left set until size of left set becomes 2 
(when we are moving the window, since before deleting the element the size of ls is 2 and rs is 1 and after delete this is changed by 1 and adding a new element again change by +1 thus to again remaintain the size we need to transfer at most 2 elements)
left set = (3, 2), (4, 1)
right set = (5, 2)


now we can give the median for this window = *left_set.rbegin();

... this way we can keep going

special case -
-- If k = 1, then right set will be empty thus we will directly print the elements itself
-- if k = 2, then we can directly return the smaller element itself




Q. Why do we need to maintain two sets? can't we use only one set
Ans. We need to maintain two sets because, at every window we need to give the median, thus breaking the complete window into two sets, we can easily return the last element of the first set which will be the median
     We can't do this with a single set, if we maintain a single set then we can't get the mid element as there is no indexing in sets.
     Thus to use single set, we can use ordered_sets.

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
        for(int i = 0; i<n; i++) cout<<values[i]<<" ";
        return 0;
    }
    if(k==2){
        for(int i = 1; i<n; i++) cout<<min(values[i-1], values[i])<<" ";
        return 0;
    }

    vector<pair<int, int>> st;
    for(int i = 0; i<k; i++) st.push_back({values[i], i});
    sort(st.begin(), st.end());
    
    for(int i = 0; i < (k+1)/2; i++) leftSet.insert(st[i]);
    for(int i = (k+1)/2; i<k; i++) rightSet.insert(st[i]);

    cout<<leftSet.rbegin()->first<<" ";

    for(int j = 1; j < n-k+1; j++){
        // erase the element
        // if(leftSet.count({values[j-1], j-1})) leftSet.erase({values[j-1], j-1});
        // else rightSet.erase({values[j-1], j-1});
        // this will take O(N)

        // erase the element
        if(make_pair(values[j-1], j-1) > *leftSet.rbegin()) rightSet.erase({values[j-1], j-1});
        else leftSet.erase({values[j-1], j-1});

        // adding the new element
        if(*(leftSet.rbegin()) < make_pair(values[j+k-1], j+k-1)) rightSet.insert({values[j+k-1], j+k-1});
        else leftSet.insert({values[j+k-1], j+k-1});

        // making the size of sets in correct order 
        // left set is smaller than required
        while (leftSet.size()<(k+1)/2)
        {
            pair<int, int> z = (*rightSet.begin());
            rightSet.erase(rightSet.begin());
            leftSet.insert(z);
        }
        // left set is greater than required
        while(leftSet.size()>(k+1)/2){
            pair<int, int> z = (*leftSet.rbegin());
            leftSet.erase(--leftSet.end());    // we can't use reverse iterator inside the erase function
            rightSet.insert(z);
        }

        // print the answer
        cout<<leftSet.rbegin()->first<<" ";
    }

    return 0;
}