#include<bits/stdc++.h>
using namespace std;
int n;
void solve(int x,string s,int a,int b){
    if(x==n*2){
        cout << s << '\n'; return;
    }
    if(b+1 <= n)
        solve(x+1,s+'(',a+1,b+1);
    if(a-1 >= 0) 
        solve(x+1,s+')',a-1,b);

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    solve(0,"",0,0);

    return 0;
}