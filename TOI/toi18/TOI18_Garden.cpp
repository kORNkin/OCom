/*
Author: kornkin.png
Algor: LIS
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, q, arr[200001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;

    vector<ll> pile;
    ll lis[n], rev[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];

        if(pile.empty() || pile.back() < arr[i]){
            pile.push_back(arr[i]);
            lis[i] = pile.size();
        }
        else {
            auto it = lower_bound(pile.begin(),pile.end(),arr[i]);
            *it = arr[i];
            lis[i] = it-pile.begin() + 1;
        }
    }
    pile.clear();
    for(int i=n-1; i>=0; i--){
        if(pile.empty() || pile.back() < arr[i]){
            pile.push_back(arr[i]);
            rev[i] = pile.size();
        }
        else {
            auto it = lower_bound(pile.begin(),pile.end(),arr[i]);
            *it = arr[i];
            rev[i] = it-pile.begin() + 1;
        }
    }

    while(q--){
        ll x; cin>>x;
        cout << min(lis[x], rev[x]) - 1 << '\n';
    }

    return 0;
}
