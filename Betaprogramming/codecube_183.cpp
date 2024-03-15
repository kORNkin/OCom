#include<bits/stdc++.h>
using namespace std;
const int N = 200001;
int bit[N], arr[N], n;

void add(int i){
    for(; i<=n; i += i&-i) bit[i]++;
}
int sum(int i){
    int ans = 0;
    for(; i>0; i-= i&-i) ans += bit[i];
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1; i<=n; i++) cin>>arr[i];
    for(int i=1; i<=n; i++){
        int x; cin>>x;
        int l=1, r=n;
        while(l < r){
            int m = (l+r)>>1;
            if(m - sum(m) < x) l = m+1;
            else r = m;
        } 
        cout << arr[l] << '\n';
        add(l);
    }
    return 0;
}