    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    const int N = 1e6;
    const int M = 1e9+7;
    int hsh[N],mem[N], P[N];
    bitset<N> vis(0);
    string s;

    void preprocess(int m){
        P[0] = 1;
        for(int i=1; i<m; i++){
            P[i] = ((ll)P[i-1]<<1)%M;
        }
    }
    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        
        int k, m; cin>> k >> m;
        preprocess(1000000);
        for(int i = 1; i <= k ; i++){
            cin >> s;
            int x = 0;
            for(int j = 0; j < m; j++){
                x += ((s[j]) * (ll)P[j]) %M;
            }
            int pos = x%N;
            while(hsh[pos]) pos++, pos %= N;
            hsh[pos] = i;
            mem[i] = x;
        }
        
        int t, x = P[m-1]; cin >> t;
        while(t--){
            int n, chk = 0; cin >> n;
            cin >> s;
            ll ht[n];
            for(int i = 0; i < m; i++){
                chk += ((s[i]) * (ll)P[i]) %M;
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
                chk -= (s[j] - '0');
                chk <<= 1;
                chk += ((s[j + m] - 48) * (ll)P[j+m-1])%M;
            }
            
            if(!vis[0]) cout << "OK";
            else for(int i = 1; i <= k; i++) if(vis[i]) cout << i << ' ';
            cout << '\n';
        }
        return 0;
    }