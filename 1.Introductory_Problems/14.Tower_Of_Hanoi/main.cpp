#include <bits/stdc++.h>
using namespace std;
// https://www.youtube.com/watch?v=pugseXz0gEk
// animation explanation - https://www.youtube.com/watch?v=rf6uf3jNjbo


/*
let we have n disks
then we have to first move n-1 disks to auxiliary tower to move the nth disk at place 
after this we are left with n-1 disks and aux as the starting tower and from as the auxiliary tower 
now we can go on to do this 
*/


void hanoi(vector<pair<int, int>> &x, int n, int from, int to, int aux){
    if(n==1){
        x.push_back({from, to});
        return;
    }

    hanoi(x, n-1, from, aux, to);
    x.push_back({from, to});
    hanoi(x, n-1, aux, to, from);
}

int main() {

    int n;
    cin>>n;

    vector<pair<int, int>> x;
    hanoi(x, n, 1, 3, 2);

    cout<<x.size()<<endl;
    for (auto move : x)
    {
        cout<<move.first<<" "<<move.second<<"\n";
    }
    

    return 0;
}