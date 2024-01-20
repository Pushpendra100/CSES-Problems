#include <bits/stdc++.h>
using namespace std;

// https://usaco.guide/problems/cses-1632-movie-festival-ii/solution
// greedy algorithm with sorting

/*
The first step is the same as that of Movie Festival question; sort the movies in increasing order of end time. 
For each movie in order, we will assign it to one of the k members to watch (or none of them)

Keep track of the time each memeber finishes watching all of his currently assigned movies in an ordered multiset. Initially, the collection consists of k zeroes.

For each movie in order, we can assign a member to watch it if there exists in the sorted collection less than or equal to the start time of the movie. if there are multiple such elements,
choose the greatest one (the member who finished watching his assigned movies the latest) ( this is because the one with smallest ending point can cover more starting points which can come in future thus we want to save this person). Assign the member to watch this movie by incrementing the answer and updating the collection accrodingly.
*/

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin>>n>>k;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) cin>>v[i].second>>v[i].first;
    sort(v.begin(), v.end()); //sort by end time - as we want to complete more things, so we want to select things which end early

    int mxMovies = 0;
    multiset<int> end_times; //// times when members will finish watching movies
    for(int i = 0; i<k; i++) end_times.insert(0);

    for(int i = 0; i < n; i++){
        auto it = end_times.upper_bound(v[i].second); // since we want the greates element which is eligible, thus we use upper_bound
        if(it == end_times.begin()) continue; // no one is free
        // assign movie
        end_times.erase(--it);
        end_times.insert(v[i].first); // this is the new ending time of that person
        ++mxMovies;
    }
    cout<<mxMovies;


    return 0;
}