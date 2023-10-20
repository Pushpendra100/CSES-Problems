#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

    int n;
    cin>>n;

    ll t_sum = n*1LL*(n+1)/2; 
    if((t_sum&1)==1){ //t_sum is odd then it can't be divided into two equal parts
        cout<<"NO"<<"\n";
        return 0;
    }
    ll sum = t_sum/2; //sum to find

    vector<int> a;
    vector<int> b;
    ll sum_ct = 0;

    for (int i = n; i >= 1; i--)
    {
        if(i+sum_ct<=sum){
            a.push_back(i);
            sum_ct+=i;
        }else{
            b.push_back(i);
        }
    }
    cout<<"YES"<<"\n";
    cout<<a.size()<<endl;
    for (int elem : a)
    {
        cout<<elem<<" ";
    }
    cout<<"\n";
    cout<<b.size()<<endl;
    for (int elem : b)
    {
        cout<<elem<<" ";
    }

    return 0;
}