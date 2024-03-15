#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> evn;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        int a, b;  cin >> a >> b;
        if(a > b) swap(a, b);
        evn.push_back({a, -1});
        evn.push_back({b, 1});
    }

    sort(evn.begin(), evn.end());

    int cnt = 0, st = -1, en;
    for(auto &[p, o] : evn){
        cnt -= o;
        if(cnt == n){   
            st = p;
        }else if(cnt == n-1 && st != -1){
            en = p;
            if(m >= st && m <= en) cout << 0;
            else if(m < st) cout << st - m;
            else cout << m - en;

            return 0;
        }
    }
    cout << -1;

    return 0;
}
