/*#include<bits/stdc++.h>
using namespace std;

int n, m, c, arr[1000001];
vector<int> ans;
deque<int> mx, mn;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> c;
    for(int i = 0; i < n; i++){
        cin >> arr[i];

        //MAX
        while(!mx.empty() && arr[i] >= arr[mx.back()]) mx.pop_back();
        while(!mx.empty() && i - mx.front() >= m) mx.pop_front();
        mx.push_back(i);

        //MIN
        while(!mn.empty() && arr[i] <= arr[mn.back()]) mn.pop_back();
        while(!mn.empty() && i - mn.front() >= m) mn.pop_front();
        mn.push_back(i);

        if(i >= m - 1 && arr[mx.front()] - arr[mn.front()] <= c) ans.push_back(i - m + 2);
    }
    for(auto &n:ans) cout << n << '\n';
    if(ans.empty()) cout << "NONE";

    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;

class st{
    int seg[2000001];
    public:
        void init(int val, int n){
            for(int i = 0; i < 2 * n; i++) seg[i] = val;
        }
        void update(int i, int val, int n, int op){ //op = 0 is mn; op = 1 is mx;
            for(seg[i += n] = val; i > 1; i >>= 1) {
                if(op) seg[i>>1] = max(seg[i], seg[i ^ 1]);
                else seg[i>>1] = min(seg[i], seg[i ^ 1]);
            }
        }
        int query(int l, int r, int n, int op){
            int res = (op? 0: 1e9);
            for(l += n, r += n; l <= r; l >>= 1, r >>= 1){
                if(op){
                    if(l&1) res = max(res, seg[l++]);
                    if(~r&1) res = max(res, seg[r--]);
                }else {
                    if(l&1) res = min(res, seg[l++]);
                    if(~r&1) res = min(res, seg[r--]);
                }
            }
            return res;
        }
} mx, mn;

int n, m, c, x;
vector<int> ans;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> c;
    mn.init(1e9, n);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        mn.update(i, x, n, 0);
        mx.update(i, x, n, 1);
    }

    for(int i = 0; i < n; i++){
        if(i > n - m ) break;
        if(mx.query(i, i + m - 1, n, 1) - mn.query(i, i + m - 1, n, 0) <= c) 
            ans.push_back(i + 1);
    }
    for(auto &n : ans) cout << n << '\n';
    if(ans.empty()) cout << "NONE";


    return 0;
}