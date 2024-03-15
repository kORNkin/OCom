#include<bits/stdc++.h>
using namespace std;

int n;
int h[10005];
int cnt[300], mem[300];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(n--){
        string s; cin >> s;   

        memset(cnt, 0, sizeof(cnt)); 
        memset(mem, 0, sizeof(mem));
        
        for(auto c : s) mem[c]++;

        string tmp;
        for(int i = 0; i < s.size(); i++){
            tmp += s[i];
            cnt[s[i]]++;
            if(s.size() % (i + 1) != 0) continue;
            int sz = s.size() / (i + 1);
            bool ch = 0;
            for(int j = 0; j <= i; j++){
                if(mem[s[j]] % cnt[s[j]] != 0){
                    ch = 1; break;
                }else if(mem[s[j]] / cnt[s[j]] != sz){
                    ch = 1; break;
                }
            }
            if(!ch) {
                cout << tmp << '\n';
                break;
            }
        }
    }

    return 0;
}
