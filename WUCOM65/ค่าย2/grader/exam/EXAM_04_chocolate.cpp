#include<bits/stdc++.h>
using namespace std;
int n,arr[1001];
int sum;

bool ch=0;
void solve(int idx,int summ){
    if(summ > sum || ch) return;
    if(summ == sum){
        cout << "YES\n"; ch=1;
        return;
    }

    for(int i=idx+1;i<n;i++){
        solve(i,summ+arr[i]);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(0);
    int T; cin>>T;
    while(T--){
        cin>>n;
        sum=0; ch=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum+= arr[i];
        }
        if(sum%2!=0) {
            cout << "NO\n";
            continue;
        } sum/=2;
        sort(arr,arr+n,greater<int>());
        solve(-1,0);
        if(!ch) cout << "NO\n";
    }

    return 0;
}
