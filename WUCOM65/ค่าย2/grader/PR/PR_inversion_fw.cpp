//แตกเพราะ size ใหญ่เกินไม่ได้
#include<bits/stdc++.h>
using namespace std;
const int N = 1000001;
int t[N], arr[N], n, inv;

void update(int i){
    for(; i < N; i += i&-i) t[i]++;
}
int sum(int i){
    int ans = 0;
    for(; i > 0; i -= i&-i) ans += t[i];
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];
    for(int i=n-1; i>=0; i--){
        inv += sum(arr[i]);
        update(arr[i]);
    }
    cout << inv;

    return 0;
}