#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin>>T;
    long long int cnt[10];
    while(T--){
        int a,b,k; cin>>a>>b>>k;
        memset(cnt,0,sizeof(cnt));
        for(int i=a;i<=b;i++){
            int x=i;
            while(x){
                cnt[x%10]++;
                x/=10;
            }
        }
        cout << cnt[k] << '\n';
    }

    return 0;
}