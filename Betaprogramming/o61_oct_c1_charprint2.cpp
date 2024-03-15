#include<bits/stdc++.h>
using namespace std;
const int N = 300001;
int t[N << 1], n, op;
long long ans;
string base, s; 
void update(int i){
    for(t[i+=n]=1; i > 1; i>>=1) t[i>>1]++;
}
int query(int l,int r){
    int res = 0;
    for(l+=n, r+=n; l<=r; l>>=1, r>>=1){
        if(l&1) res += t[l++];
        if(!(r&1)) res += t[r--];
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>op>>base>>s;
    vector<int> v[26];
    n = base.size();
    for(int i=n-1; i>=0; i--)
        v[base[i]-'a'].push_back(i);
    if(op){
        for(int i=0;i<s.size();i++){
            if(v[s[i]-'a'].empty()){
                cout << -1; return 0;
            }
            int idx = v[s[i]-'a'].back();
            ans-=query(0,idx);
            ans+=idx+1;
            v[s[i]-'a'].pop_back();
            update(idx);
        }
    }else {
        for(int i=0;i<s.size();i++){
            if(v[s[i]-'a'].empty()){
                cout << -1; return 0;
            }
            ans+=v[s[i]-'a'].back()+1;
            v[s[i]-'a'].pop_back();
        }
    } cout << ans;

    return 0;
}