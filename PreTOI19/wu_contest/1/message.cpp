#include<bits/stdc++.h>
using namespace std;

int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(n--){
        string s; cin >> s;
        bool ch = 0;
        for(int i = 1; i < s.size() / 2; i++){
            if(s[i] != s[i - 1]) {
                ch = 1; break;
            }
        }
        cout << (ch ? "YES\n" : "NO\n");
    }

    return 0;
}
/*
3
aba
bbbbb
avcxcva
*/
/*
5
agaaga
dd
vibebiv
goosesoog
dvd
*/