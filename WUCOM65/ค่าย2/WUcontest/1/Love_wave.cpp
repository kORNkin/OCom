#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    while(n--){
        int cnt=0;
        string s; cin>>s;
        bool ch=0;
        for(auto c:s){
            if(c=='I') cnt++;
            else if(cnt) cnt--;
            else {
                ch=1;
                break;
            }
        }
        if(ch || cnt) cout << "N\n";
        else cout << "Y\n";
    }

    return 0;
}