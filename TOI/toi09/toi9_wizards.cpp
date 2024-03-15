//hash table ~600 ms
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e6+11;
struct P{
    ll x, y;
} arr[4][1501];
ll n, xt, yt;
pair<ll,ll> h[N], val[N];
bitset<N> vis;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    cin >> xt >> yt >> n;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j].x >> arr[i][j].y;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ll x = xt - arr[0][i].x - arr[1][j].x;
            ll y = yt - arr[0][i].y - arr[1][j].y;
            int idx = ((x * 53 + y)%N + N)%N;
            while(vis[idx]) idx = (idx + 1)%N;
            vis[idx] = 1;
            h[idx] = {i,j};
            val[idx] = {x,y};
        }
    } 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ll tarx = arr[2][i].x + arr[3][j].x;
            ll tary = arr[2][i].y + arr[3][j].y;
            int idx = ((tarx * 53 + tary)%N + N)%N;
            while(vis[idx]){
                if(val[idx].first == tarx && val[idx].second == tary){
                    cout << arr[0][h[idx].first].x << ' ' << arr[0][h[idx].first].y << '\n';
                    cout << arr[1][h[idx].second].x << ' ' << arr[1][h[idx].second].y << '\n';
                    cout << arr[2][i].x << ' ' << arr[2][i].y << '\n';
                    cout << arr[3][j].x << ' ' << arr[3][j].y << '\n';
                    return 0;
                }
                idx = (idx + 1)%N;
            }
        }    
    }   
    
    return 0;
}

/*
//bsearch ~1000 ms
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
struct P{
    ll x, y;
    bool operator < (P &r){
        return (x == r.x? y < r.y: x < r.x);
    }
} arr[4][1501];
ll n, xt, yt;
vector<tuple<ll,int,int>> v;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    cin >> xt >> yt >> n;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j].x >> arr[i][j].y;
        }
        sort(arr[i], arr[i] + n);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            v.emplace_back(xt - arr[0][i].x - arr[1][j].x, i, j);
        }
    } sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ll tar = arr[2][i].x + arr[3][j].x;
            int l = 0, r = n*n-1;
            while(l < r){
                int m = (l+r)>>1;
                if(get<0>(v[m]) >= tar) r = m; 
                else l = m + 1;
            }
            ll sum = arr[2][i].y + arr[3][j].y;
            while(get<0>(v[l]) == tar && l < n*n){
                if(arr[0][get<1>(v[l])].y + arr[1][get<2>(v[l])].y + sum == yt){
                    cout << arr[0][get<1>(v[l])].x << ' ' << arr[0][get<1>(v[l])].y << '\n';
                    cout << arr[1][get<2>(v[l])].x << ' ' << arr[1][get<2>(v[l])].y << '\n';
                    cout << arr[2][i].x << ' ' << arr[2][i].y << '\n';
                    cout << arr[3][j].x << ' ' << arr[3][j].y;
                    return 0;
                } ++l;
            }       
        }    
    }   
    
    return 0;
}
*/