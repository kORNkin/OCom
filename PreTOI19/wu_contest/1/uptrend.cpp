#include<bits/stdc++.h>
using namespace std;

int n, x;
vector<int> v;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        auto it = upper_bound(v.begin(), v.end(), x);
        if(it == v.end()) v.push_back(x);
        else *it = x;
    }
    cout << v.size();

    return 0;
}
