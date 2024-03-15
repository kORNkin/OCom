#include <bits/stdc++.h>
using namespace std;
int n=10,cnt=0;
void bcounter(int i,string ans){
    if(i==n){
        if(ans.find("11111")!=-1 || ans.find("00000")!=-1)
            cout << ans << '\n',cnt++;
    
        return;
    }

    bcounter(i+1,ans+'0');
    bcounter(i+1,ans+'1');
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

    bcounter(0,"");
    cout << cnt;

    return 0;
}
