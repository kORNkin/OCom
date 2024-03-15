#include<bits/stdc++.h>
using namespace std;
struct stone{
    int mn, idx, ty, hf;
    bool operator < (const stone &r) const{
        return (mn == r.mn? idx > r.idx: mn < r.mn);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<stone> pq;
    int T, ans = 0; cin >> T;
    for(int i = 1; i <= T; i++){           
        while(!pq.empty() && pq.top().ty == 1){
            int idx = pq.top().idx, hf = pq.top().hf, mn = pq.top().mn;
            if(idx + hf <= i) {
                pq.pop(); if((mn>>1) > 0) pq.push({mn >> 1, idx + hf, 1, hf});
            }else break;
        }
        char op; cin >> op;
        if(op == 'c'){
            char ty; cin >> ty;
            int x, y;
            if(ty == 'n') cin >> x, pq.push({x, i, 0, -1});
            else cin >> x >> y, pq.push({x, i, 1, y});
        } else {

            if(!pq.empty()){
                ans += pq.top().mn;
                pq.pop();
            }
        }
    }
    int sz = pq.size();
    while(!pq.empty()){
        if(pq.top().ty == 1){
            int idx = pq.top().idx, hf = pq.top().hf, mn = pq.top().mn;
            if(idx + hf <= T) {
                if((mn>>1) > 0) pq.push({mn >> 1, idx + hf, 1, hf});
                else sz--;
            }
        }
        pq.pop();
    }
    cout << ans << '\n' << sz;

    return 0;
}
