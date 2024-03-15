#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll arr[200005], dis[200005];

struct Node{
    double cst; 
    ll idx;
    bool operator < (const Node &r) const{
        if(cst == r.cst) return idx < r.idx;
        return cst > r.cst;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,c;
    cin >> n >> c;
    for(int i = 0; i < n; i++) cin >> arr[i], dis[i] = LLONG_MAX;

    priority_queue<Node> pq;
    pq.push({0, 0});
    dis[0] = 0;
    while(!pq.empty()){
        Node now = pq.top();
        pq.pop();

        if(now.idx == n - 1){
            cout << dis[now.idx];
            break;
        }

        for(int i = now.idx + 1; i < n; i++){
            ll tar = dis[now.idx] + pow(arr[i] - arr[now.idx], 2) + c;
            if(dis[i] > tar){
                dis[i] = tar;
                pq.push({(double)dis[i] / (i+1), i});
            }
        }
    }

    return 0;
}

