#include <bits/stdc++.h>
using namespace std;
int k;
void solve(int w,int l,string ans){
    if(w+l==2*k-1 || w==k || l==k){
        cout << ans << '\n';
        return;
    }

    solve(w+1,l,ans+"W ");
    solve(w,l+1,ans+"L ");
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int w,l;
    cin>>k>>w>>l;
    solve(w,l,"");

    return 0;

}