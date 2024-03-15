#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
const int INF = 2e9;
const int N = 3 * 40001;

class Segment{
    vector<int> seg;

    public:
        void init(){ seg = vector<int>(N, INF); }

        void update(int i, int n, int val){
            if(seg[i+=n] <= val) return;
            for(seg[i] = val; i > 1; i >>= 1) seg[i>>1] = min(seg[i], seg[i ^ 1]);
        }

        int query(int l, int r, int n){
            int res = INF;
            for(l+=n, r+=n; l <= r; l>>=1, r>>=1){
                if(l&1) res = min(res, seg[l++]);
                if(!(r&1)) res = min(res, seg[r--]);
            }
            return res;
        }
} sl, sr;

struct Node{
    int x, y, t;
    bool operator < (const Node &r) const{
        if(x == r.x) return (y == r.y? t < r.t: y < r.y);
        return x < r.x;
    }
};

int m, n, k, p, dp[20010][20], sz_col, cmps[40010], lside, rside;
Node node[40010];
map<Node, Node> mp;
map<Node, int> get_idx;
Node in[20010], out[20010];
vector<int> col;

void setDp(){
    for(int i = 1; i <= 20001; i++){
        for(int j = 0; j <= 17; j++){
            dp[i][j] = INF;
        }
    }
}

void coor_compress(){
    sort(col.begin(), col.end());
    col.erase(unique(col.begin(), col.end()), col.end());
    sz_col = col.size();
    for(int i = 1; i <= 2 * k; i++){
        cmps[i] = lower_bound(col.begin(), col.end(), node[i].y) - col.begin() + 1;
    }
}

void setNode(){
    int idx = 1;
    for(int i = 1; i <= 2 * k; i++){
        if(!node[i].t){
            in[idx] = node[i];
            out[idx] = mp[node[i]];
            get_idx[node[i]] = idx;
            get_idx[mp[node[i]]] = idx;
            ++idx;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> k >> p;
    for(int i = 1; i <= k; i++){
        int sx, sy, dx, dy;
        cin >> sx >> sy >> dx >> dy;
        node[i * 2 - 1] = {sx, sy, 0};
        node[i * 2] = {dx, dy, 1};
        mp[{sx, sy, 0}] = {dx, dy, 1};
        mp[{dx, dy, 1}] = {sx, sy, 0};
        col.push_back(sy);
        col.push_back(dy);
    }

    setDp();
    sort(node + 1, node + 1 + 2 * k);
    coor_compress();
    setNode();

    int ans = m + n - 2, ansp = 0;

    for(int i = 1; i <= k; i++) dp[i][0] = out[i].x + out[i].y - 2;
    for(int i = 1; i <= k; i++){
        dp[i][1] = min(dp[i][0], in[i].x + in[i].y - 2);

        if(ans > m + n - out[i].x - out[i].y + dp[i][1]){
            ans = m + n - out[i].x - out[i].y + dp[i][1];
            ansp = 1;
        }
    }

    for(int pp = 2; pp <= p; pp++){
        sl.init(); sr.init();

        for(int i = 1; i <= k; i++) dp[i][pp] = dp[i][pp-1];

        for(int i = 1; i <= 2 * k; i++){
            if(node[i].t){
                sl.update(cmps[i], sz_col, dp[get_idx[node[i]]][pp-1] - node[i].x - node[i].y);
                sr.update(cmps[i], sz_col, dp[get_idx[node[i]]][pp-1] - node[i].x + node[i].y);
            }else {
                lside = sl.query(1, cmps[i], sz_col) + node[i].x + node[i].y;
                rside = sr.query(cmps[i], sz_col, sz_col) + node[i].x - node[i].y;
                dp[get_idx[node[i]]][pp] = min({dp[get_idx[node[i]]][pp], lside, rside});
            } 
        }

        sl.init(); sr.init();

        for(int i = 2 * k; i >= 1; i--){
            if(node[i].t){
                sl.update(cmps[i], sz_col, dp[get_idx[node[i]]][pp-1] + node[i].x - node[i].y);
                sr.update(cmps[i], sz_col, dp[get_idx[node[i]]][pp-1] + node[i].x + node[i].y);
            }else {
                lside = sl.query(1, cmps[i], sz_col) - node[i].x + node[i].y;
                rside = sr.query(cmps[i], sz_col, sz_col) - node[i].x - node[i].y;
                dp[get_idx[node[i]]][pp] = min({dp[get_idx[node[i]]][pp], lside, rside});
            }
        }

        for(int i = 1; i <= k; i++){
            if(ans > m + n - out[i].x - out[i].y + dp[i][pp]){
                ans = m + n - out[i].x - out[i].y + dp[i][pp];
                ansp = pp;
            }
        }
    }
    
    cout << ans << ' ' << ansp;

    return 0;
}