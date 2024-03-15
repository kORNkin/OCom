#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int n, t, ans, prv;
vector<tuple<int, int, int>> evn;

class BIT{
    int fw[N];
    public:
        void add(int i, int val){
            for(; i <= N; i += i&-i) fw[i] += val;
        }
        int query(int i){
            int res = 0;
            for(; i >= 1; i -= i&-i) res += fw[i];
            return res;
        }
        int idx(int k){
            int l = 0, r = N;
            while(l < r){
                int m = (l + r + 1)>>1;
                if(query(m) > k) l = m;
                else r = m - 1;
            }
            return l;
        }

} fw;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n >> t;
    for(int i = 0; i < n; i++) {
        int s, h, w, o;
        cin >> s >> h >> w >> o;
        evn.push_back({s, h, o});
        evn.push_back({s + w, h, -o});
    }

    sort(evn.begin(), evn.end());

    for(auto &[s, h, o] : evn){
        
        ans += (s - prv) * (fw.idx(t - 1) - fw.idx(t)); 
        prv = s;

        fw.add(1, o);
        fw.add(h + 1, -o);
    }
    cout << ans;

    return 0;
}