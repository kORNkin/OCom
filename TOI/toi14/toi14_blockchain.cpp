#include<bits/stdc++.h>
using namespace std;

map<vector<pair<int, int>>, int> mp; 
bitset<1025> valid;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, q; cin >> t >> q;
    for(int i = 0; i < t; i++){
        int n; cin >> n; 
        valid[n] = 1;
        vector<pair<int, int>> g;
        for(int j = 0; j < n - 1; j++){
            int u, v; cin >> u >> v; g.push_back({min(u, v),max(u, v)});
        } sort(g.begin(), g.end());
        ++mp[g];
    }

    for(int i = 0; i < q; i++) {
        int n; cin >> n;

        vector<pair<int, int>> g;
        for(int j = 0; j < n - 1; j++){
            int u, v; cin >> u >> v; g.push_back({min(u, v),max(u, v)});
        }         

        if(!valid[n]) {
            cout << "0\n"; continue;
        }

        sort(g.begin(), g.end());
        cout << mp[g] << '\n';
    }

    return 0;
}