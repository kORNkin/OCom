#include<bits/stdc++.h>
using namespace std;
const int N = 200001;
int t[N<<1], arr[N], n;

void build(){
    for(int i = n-1; --i;) t[i] = t[i<<1] + t[i<<1|1];
}
void update(int i){
    for(t[i+=n] = 0; i > 1; i>>=1) t[i>>1] = t[i] + t[i^1]; 
}
int query(int l,int r){
    int ans=0;
    for(l+=n, r+=n; l<=r; l>>=1, r>>=1){
        if(l&1) ans += t[l++];
        if(!(r&1)) ans += t[r--];
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i], t[i + n]=1;
    build();
    for(int i=0; i<n; i++){
        int x; cin>>x;
        int l=0,r=n-1;
        while(l < r){
            int m = (l+r)>>1;
            if(query(0,m) >= x) r = m;
            else l = m+1;
        }
        cout << arr[l] << '\n';
        update(l);
    }
    return 0;
}