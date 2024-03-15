#include<bits/stdc++.h>
using namespace std;
int n,m;
int co=0,sum=0;
string ans;
bool ch=0;
void solve(){
    if(ch || sum > n) return;
    if(sum == n){
        cout <<ans << " " << sum << '\n';
        co++;
        if(co==m) {
            //cout << ans << " " << sum;
            ch=1;
        }
        return ;
    }
    for(int i=1;i<=9;i++){
        ans+= i+'0';
        sum+=i;
        solve();
        sum-=i;
        ans.pop_back();
        
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=9;i++){
        ans+=i+'0';
        sum+=i;
        solve();
        sum-=i;
        ans.pop_back();
        if(ch) break;
    }

    return 0;
}