#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin>>T;
    
    while(T--){
        int n,m; cin>>n>>m;
        string s; cin>>s;
        int cnt[26]; memset(cnt,0,sizeof(cnt));
        for(auto c:s)
            cnt[c-'a']++;
        bool ch=1;
        for(int i=0;i<26;i++){
            if(cnt[i] && cnt[i]>m){
                ch=0;
                break;
            }
        }
        if(ch) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}