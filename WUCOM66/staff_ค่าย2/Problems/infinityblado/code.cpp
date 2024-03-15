/*
Problem: infinityblado
Algor: Greedy + Sorting + STL
Author: kornkin
*/
#include<bits/stdc++.h>
using namespace std;

long long arr[1000001], amt[1000001];
unordered_map<string, int> mp;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    long long n, m, sum = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < m; i++){
        string tmp; cin >> tmp;
        mp[tmp]++;
    }

    m = 0;
    for(auto i:mp){
        amt[m++] = i.second;
    }

    sort(amt, amt + m, greater<int>());

    sort(arr, arr + n);
    for(int i = 0; i < m; i ++){
        sum += amt[i] * arr[i]; 
    }

    cout << sum << ' ';

    sort(arr, arr + n, greater<int>());
    sum = 0;
    for(int i = 0; i < m; i ++){
        sum += amt[i] * arr[i]; 
    }

    cout << sum;

    return 0;
}
