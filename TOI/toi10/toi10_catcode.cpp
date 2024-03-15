#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
int hsh[N],mem[N];
bitset<N> vis(0);
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int k, m; cin>> k >> m;
    for(int i = 1; i <= k ; i++){
        cin >> s;
        int x = 0;
        for(int j = 0; j < m; j++){
            x <<= 1;
            x |= s[j] - 48; 
        }
        int pos = x%N;
        while(hsh[pos]) pos++, pos %= N;
        hsh[pos] = i;
        mem[i] = x;
    }
    
    int t, x = 1<<(m - 1); cin >> t;
    while(t--){
        int n, chk = 0; cin >> n;
        cin >> s;
        for(int i = 0; i < m; i++){
           chk <<= 1;
           chk |= s[i] - 48; 
        } 
        
        vis.reset();
        for(int j = 0; j <= n - m; j++){
            int pos = chk%N;
            while(hsh[pos]){
                if(mem[hsh[pos]] == chk){
                    vis[hsh[pos]] = 1; 
                    vis[0] = 1;
                    break;
                }
                pos++;
                pos %= N;
            }
            chk -= (s[j] - '0') * x;
            chk <<= 1;
            chk |= (s[j + m] - 48);
        }
        
        if(!vis[0]) cout << "OK";
        else for(int i = 1; i <= k; i++) if(vis[i]) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}