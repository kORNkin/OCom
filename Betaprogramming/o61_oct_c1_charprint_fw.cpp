#include<bits/stdc++.h>
using namespace std;
const int N = 300001;
int t[N], op, n;
long long sum;
vector<int> v[26];
string base, s;

void update(int i){
    for(; i <= n; i += i&-i) t[i]++;
}
int query(int i){
    int ans = 0;
    for(; i > 0; i -= i&-i) ans += t[i];
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>op>>base>>s;
    n = base.size();
    for(int i=n-1; i>=0; i--)
        v[base[i]-'a'].push_back(i);

    for(int i=0; i<s.size(); i++){
        if(v[s[i]-'a'].empty()){
            cout << -1; return 0;
        }
        int idx = v[s[i]-'a'].back()+1;
        sum += idx - query(idx);
        if(op) update(idx);
        v[s[i]-'a'].pop_back();
    }
    cout << sum;

    return 0;
}