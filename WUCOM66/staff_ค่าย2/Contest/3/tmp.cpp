#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll arr[200005], dis[200005];

ll s[1001][1001];

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
    for(int i = 1; i <= n; i++) cin >> arr[i], dis[i] = LLONG_MAX;

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            s[i][j] = (arr[j] - arr[i]) * (arr[j] - arr[i])  + c;
        }
    }
    cout << setw(6);
    for(int i = 0; i <= n; i++) cout << setw(3) << arr[i] << ' ';
    cout << '\n';
    for(int i = 1; i <= n; i++){
        cout << setw(3);
        cout << arr[i] << ' ';
        for(int j = 1; j <= n; j++){
            cout << setw(3);
            cout << s[i][j] << ' ';
        } cout << '\n';
    }

    priority_queue<Node> pq;
    pq.push({0, 1});
    dis[1] = 0;
    while(!pq.empty()){
        Node now = pq.top();
        pq.pop();

        if(now.idx == n - 1){
            //cout << dis[now.idx];
            //break;
        }

        for(int i = now.idx + 1; i <= n; i++){
            ll tar = dis[now.idx] + pow(arr[i] - arr[now.idx], 2) + c;
            if(dis[i] > tar){
                dis[i] = tar;
                pq.push({(double)dis[i] / (i+1), i});
            }
        }
    }

    cout << "\n\n";
    for(int i = 1; i <= n; i++) cout << arr[i] << ' ';
    cout << '\n';
    for(int i = 1 ;i <= n; i++) cout << dis[i] << ' ';
    return 0;
}


/*

5 6
1 2 3 4 5

8 5
1 3 4 5 10 11 12 13
*/