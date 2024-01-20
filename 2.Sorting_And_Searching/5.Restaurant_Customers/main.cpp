#include <bits/stdc++.h>
using namespace std;

/*
In this problem, we're given n intervals with distinct start and end points, and we want to find the maximum number of intervals overlapping at some point

#SOLUTION
we can use prefix sums to determine the number of intervals that cover any particular point, and then find the maximum number in the sum
but since a, b <= 10^9, and we will run out of memory when creating an array of size a. Thus we can either coordinate compress and compute the prefix sum over interesting intervals or sweep over the intervals while maintaining a running prefix sum.
*/


// IMPLEMENTATION 1
/*
If we put the start and end points into a list and sort them, all we need to do is find the max sum of values over all prefixes of the list
*/
// int32_t main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n; cin>>n;
//     vector<pair<int, int>> times;
//     for(int i = 0; i < n; i++){
//         int start, end;
//         cin>>start>>end;
//         times.push_back({start, 1});
//         times.push_back({end, -1});
//     }

//     sort(times.begin(), times.end());

//     int curr_ppl = 0;
//     int max_ppl = 0;
//     for(auto &t: times){
//         curr_ppl += t.second;
//         max_ppl = max(max_ppl, curr_ppl);
//     }
//     cout<<max_ppl<<"\n";
//     return 0;
// }



// IMPLEMENTATION
/* 
    Coordinate compress interval endpoints and only compute the prefix sum array for interesting intervals
*/
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    vector<pair<int, int>> times;
    for(int i = 0; i<n; i++){
        int start, end;
        cin>>start>>end;
        times.push_back({start, 1});
        times.push_back({end + 1, -1});
    }

    sort(times.begin(), times.end());

    int curr = 0;
    int at = 0;

    // stores how much the no. of people in the restaurant each time step
    vector<int> ppl_change(2*n);
    // compress the starting & ending events into a single array
    for(int i = 0; i<2*n; i++){
        if(i==0){
            times[i].first = 0;
        }else if(times[i].first > curr){
            at++;
            curr = times[i].first;
        }
        ppl_change[at+1] += times[i].second;
    }

    //build our prefix sum array
    vector<int> ppl_amt(2*n+1);
    for(int i = 1; i<2*n+1; i++){
        ppl_amt[i] = ppl_change[i-1] + ppl_amt[i-1];
    }

    // our answer is just the maximum of the prefix sum array
    int max_ppl = 0;
    for(int i = 0; i < 2*n+1; i++) max_ppl = max(max_ppl, ppl_amt[i]);

    cout<<max_ppl<<endl;

    return 0;
}