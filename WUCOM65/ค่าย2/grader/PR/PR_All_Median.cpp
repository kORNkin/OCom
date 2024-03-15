#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int, vector<int>, greater<int>> mn;
    priority_queue<int> mx;
    mx.push(-1), mn.push(1e9);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;

        if(x > mx.top()) mn.emplace(x);
        else mx.emplace(x);

        while(mn.size() > mx.size()){
            mx.emplace(mn.top());
            mn.pop();
        }
        while(mx.size() - 1 > mn.size()){
            mn.emplace(mx.top());
            mx.pop();
        }

        if(i&1)  cout << fixed  << setprecision(1) << (mn.top() + mx.top()) / 2.0 << '\n';
        else cout << fixed  << setprecision(1) << (double)mx.top() << '\n';
    }
    return 0;
}
