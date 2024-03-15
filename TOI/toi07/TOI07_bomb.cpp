#include <bits/stdc++.h>
using namespace std;
void scan(int &n){
    char c = getchar(); n = 0;
    if(c <= 47 || c >= 58) c = getchar();
    for(; c > 47 && c < 58; c = getchar())
        n = n * 10 + c - 48;
}

int n, mx;
pair<int, int> p[1000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    scan(n);
    for(int i = 0; i < n; i++){
        scan(p[i].first), scan(p[i].second);
    }
    sort(p, p + n, [&](pair<int, int> a, pair<int, int> b){
        return (a.first == b.first? a.second < b.second: a.first > b.first);
    }); 
    vector<pair<int, int>> ans;
    for(int i = 0; i < n; i++){
        if(mx > p[i].second) continue;
        mx = p[i].second;
        ans.push_back(p[i]);
    } 
    reverse(ans.begin(), ans.end());
    for(auto pp:ans) cout << pp.first << ' ' << pp.second << '\n';

    return 0;
}