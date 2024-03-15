#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
vector<pair<int ,int>> arr;

void compress(){
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    v.push_back(INT_MIN);
    v.push_back(INT_MAX);
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        v.push_back(a);
        v.push_back(b);
        arr.push_back({a, b});
    }   

    compress();

    int qs[v.size()]; memset(qs, 0, sizeof(qs));

    for(int i = 0; i < n; i++){
        int idx = lower_bound(v.begin(), v.end(), arr[i].first) - v.begin();
        qs[idx]++;
        idx = lower_bound(v.begin(), v.end(), arr[i].second) - v.begin();
        qs[idx]--;
    }

    int mx = 0;
    for(int i = 1; i < v.size(); i++)
        qs[i] += qs[i - 1], mx = max(mx, qs[i]);

    cout << mx;

    return 0;
}
