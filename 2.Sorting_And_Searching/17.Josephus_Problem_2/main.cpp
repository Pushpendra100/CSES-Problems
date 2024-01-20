#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// https://www.youtube.com/watch?v=KnsDFCcBJbY

/*

We have to remove elements and insert elements, thus we can get using set
but we also need properties of array like value at x position or what is the kth smallest value and we want this operation in log(n) time

This data structure does not belong to the standard library of c++ but we can use them 
Policy based data structure
we are using ordered sets


Ordered sets
It perfoms all the operations as performed by the set data structure in STL in log(n) complexity and performs two additional operations also in log(n) complexity
- order_of_key(k): Number of items strictly smaller than k
- find_by_order(k): k-th element in a set(counting from zero)


*/

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin>>n>>k;
    ordered_set<int> children;
    for(int i = 1; i <= n; i++){
        children.insert(i);
    }
    int startPosition = 0;
    while(children.size() > 0){
        startPosition %= children.size();
        int positionToRemove = (startPosition + k)%children.size();
        startPosition = positionToRemove;
        auto t = children.find_by_order(positionToRemove);
        cout<<*t<<" ";
        children.erase(t);
    }

    return 0;
}