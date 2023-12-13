#include <bits/stdc++.h>
using namespace std;

// https://usaco.guide/problems/cses-1160-planets-queries-ii/solution

/*
Functional Graph - Directed graphs in which every has exactly one outgoing edge
// then we can say that in a functional graph and in one of its component 
there can be only one cycle and all other node connected to it will form a tree directed towards cycle



Now considering both u and v (be in the same component) given in the query there are three cases:-
1. Both in tree
    - If both u and v are in a tree, we first have to get the distance from each node to the cycle. This can be precalculated for all nodes with BFS.
    - First of all, if v's distance is greater than that of u's, we can't get to v because using a teleporter can only decrease our distance to the cycle.
    - But if this condition isn't satsified, we start at u and use the teleporters until our distance to the cycle is equal to that of v's. If we've actually
      ended up at v, then our answer is the difference between the distances. Otherwise, it's impossible to reach v.
    - To see which planet we end up at if we teleport t times, we can use binary jumping.
2. Both in cycle
    if both are in cycle, we got both u and v's index in the cycle. Let's call these indices ui and vi resp. Now, if ui<=vi, then our answer is vi-ui.
    On the other hand, if ui>vi, then our answer is cycle_len - (ui-vi).
3. one in each
    - if u is in a cycle but v is in a tree, it's impossible to reach v from u because we can only go from a tree to a cycle, not vice versa
    - if u is the one in the tree, we get which node in the cycle u's tree connects to, which is also the root. Then this reduces to a version
        of the second case: we just have to add the distance from u to the root as well.


Now if u and v are in different components we can't reach v
*/



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;
    vector<int> next(n);
    vector<vector<int>> before(n);
    for(int p = 0; p<n; p++){
        cin>>next[p];
        next[p]--;
        before[next[p]].push_back(p);
    }

    /*
        -2 = We haven't even got to processing this planet yet
        -1 = This node is part of a tree
        >= 0 the ID of the cycle the planet belongs to
    */
   vector<int> cycle_id(n, -2);

   // each map, given a planet #, returns the index of the planet in the cycle
   vector<map<int, int>> cycles;
   // for loop on every node to find out node is part of a tree or a cycle, if part of cycle then capture the cycle
   for(int p = 0; p<n; p++){
        if(cycle_id[p] != -2) continue;
        vector<int> path{p};
        int at = p;
        while(cycle_id[next[at]]==-2){
            at = next[at];
            cycle_id[at] = -3; //leave breadcrumbs for this iteration
            path.push_back(at);
        }

        map<int, int> cycle;
        bool in_cycle = false;
        for(int i : path){
            in_cycle = in_cycle || i == next[at];
            if(in_cycle) cycle[i] = cycle.size();
            cycle_id[i] = in_cycle? cycles.size() : -1;
        }
        cycles.push_back(cycle);
   }


   /*
   Precalculate the distance from each planet to its cycle with BFS.
   (cyc_dist[p]=0) if p is a part of a cycle
   */

  vector<int> cyc_dist(n);
  for(int p = 0; p<n; p++){
    // check if the planet is part of a cycle
    if(cycle_id[next[p]]==-1 || cycle_id[p] != -1) continue;
    cyc_dist[p] = 1;
    vector<int> stack(before[p]);
    while (!stack.empty())
    {
        int curr = stack.back();
        stack.pop_back();
        cyc_dist[curr] = cyc_dist[next[curr]] +1;
        stack.insert(stack.end(), before[curr].begin(), before[curr].end());
    }
  }

  // Initialize the binary jumping arrays
  int lg2 = ceil(log2(n));
  vector<vector<int>> pow2_ends(n, vector<int>(lg2+1));
  for(int p = 0; p<n; p++) pow2_ends[p][0] = next[p];
  for(int i = 1; i<=lg2; i++){
    for(int p = 0; p<n; p++){
        pow2_ends[p][i] = pow2_ends[pow2_ends[p][i-1]][i-1];
    }
  }

    /*
    Given a starting planet Precalculate the distance from each planet to its cycle with BFS.
   (cyc_dist[p]=0) if p is a part of a cycle& dist, returns the planet we end up at if we use the teleporter dist times
    */

   auto advance = [&](int pos, int dist){
    for(int pow = lg2; pow>=0; pow--){
        if((dist & (1<<pow)) != 0) pos = pow2_ends[pos][pow];
    }
    return pos;
   };

    while (q--)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        if(cycle_id[pow2_ends[u][lg2]] != cycle_id[pow2_ends[v][lg2]]){ //checks whether they are in different cycles
            cout<<-1<<"\n";
            continue;
        }
        if(cycle_id[u] != -1 || cycle_id[v]!=-1){ //any one or both in cycle
            if(cycle_id[v] == -1 && cycle_id[u] != -1){
                cout<<-1<<"\n";
                continue;
            }
            // handle the 2nd and 3rd cases at the same time
            int dist = cyc_dist[u];
            int u_cyc = advance(u, cyc_dist[u]); //The root of u's tree

            map<int, int> &cyc = cycles[cycle_id[u_cyc]];  // u and v's cycle
            int u_ind = cyc[u_cyc];
            int v_ind = cyc[v];
            int diff = u_ind<=v_ind? v_ind - u_ind:cyc.size() - (u_ind - v_ind);
            cout<<dist+diff<<"\n";
        }else{ //both in tree
            if(cyc_dist[v] > cyc_dist[u]){
                cout<<-1<<"\n";
                continue;
            }
            int diff = cyc_dist[u] - cyc_dist[v];
            cout<<(advance(u, diff) == v? diff: -1)<<"\n";
        }
    }
    

    return 0;
}