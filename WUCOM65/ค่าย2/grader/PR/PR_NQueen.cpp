#include<bits/stdc++.h>
using namespace std;
int n;
int col[10001];

bool valid(int j){
    for(int i=1;i<j;i++){
        if(col[i] == col[j] || abs(col[j] - col[i]) == j-i)
            return 0;
    }
    return 1;
}
int cnt=0;
void solve(int j){
    if(j==n){
        cnt++;
        cout << '[';
        for(int i=1;i<=n;i++){
            cout << col[i] << ' ';
        }cout << "] ";
        return ;
    }
    for(int i=1;i<=n;i++){
        col[j+1]=i;
        if(valid(j+1)){
            solve(j+1);
        }
    }
}

int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(0);

    int T; cin>>T;
    while(T--){
        cin>>n;
        memset(col,0,sizeof(col));
        solve(0);
        if(!cnt) cout << "-1\n";
        cout << '\n';        
    }

    return 0;
}