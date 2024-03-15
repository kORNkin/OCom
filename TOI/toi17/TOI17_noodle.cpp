#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void scan(int &n){
    char c; n = 0;
    c = getchar();
    if(c <= 47 || c >= 58) c = getchar();
    for(; c > 47 && c < 58; c = getchar())
        n = n * 10 + c - 48;
}

int n, m, k, arr[100001];
priority_queue<int, vector<int>, greater<int>> pq;
bool solve(ll &cur){
    int sum = 0, cnt = 0;

    for(int i = 0; i < n; i++){
        pq.push(arr[i]);
        sum += arr[i];
        if(pq.size() > k){
            sum -= pq.top();
            pq.pop();
        }
        if(sum >= cur && pq.size() == k){
            cnt++;
            sum = 0;
            pq = {};
        }
    }
    pq = {};

    if(cnt < m) return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    scan(n), scan(m), scan(k);
    for(int i = 0; i < n; i++) scan(arr[i]);
    ll l = 0, r = 2e9;
    while(l < r){
        ll mid = (l + r + 1) >> 1;
        if(solve(mid)) r = mid - 1;
        else l = mid; 
    }
    cout << l;

    return 0;
}