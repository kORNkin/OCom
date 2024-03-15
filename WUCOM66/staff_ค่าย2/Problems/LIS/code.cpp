#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, t; cin >> n >> t;

    vector<int> v;
    for(int i = n - 1; i >= 0; i--){
        int x, s; cin >> x >> s;
        x = - (x + s * t);
        if(v.empty() || v.back() <= x) {
            v.push_back(x);
        }
        else {
            auto it = upper_bound(v.begin(),v.end(), x);
            *it = x;
        }
    }

    cout << v.size() << '\n';

    return 0; 
}