#include<bits/stdc++.h>
using namespace std;
int arr[10001];
int n,cnt=0;;
bool row[1001],xy[1001],yx[1001];
void solve(int i){
    if(i==n){
        cout << '[';
        for(int k=0;k<n;k++){
            cout << arr[k]+1 << ' ';
        } cout << "] ";
        cnt++;
        return;
    }
    for(int j=0;j<n;j++){
        if(row[j] || xy[i+j] || yx[i-j+n]) continue;
        row[j]=1;
        xy[i+j]=1;
        yx[i-j+n]=1;
        arr[i]=j;
        solve(i+1);
        row[j]=0;
        xy[i+j]=0;
        yx[i-j+n]=0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin>>T;
    while(T--){
        cin>>n;
        solve(0);
        if(!cnt) cout << "-1\n";
        cout << '\n';
    }

    return 0;
}