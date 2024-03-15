#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int n,m;
long long g[1001][1001];
long long dp[1001][1001];
bool notP[100001];
int k[100001];
vector<int> prime;
void primeSeive(){
    prime.push_back(2);
    memset(notP,0,sizeof(notP));
    for(int i=2;i<100001; i+=2)
        notP[i] = 1;
    for(int i=3;i<100001; i+=2){
        if(!notP[i]){
            prime.push_back(i);
            for(int j=i+i;j<100001; j+=i)
                notP[j] = 1; 
        }
    }
}

void solve(int kk){
    k[1]=0;
    int x = kk;
    int cnt=0;
    for(auto e:prime){
        if(x==1) break;
        while(x%e == 0){
            x/=e;
            cnt++;
        }
    }
    k[kk] = cnt;
}

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    primeSeive();
    memset(k,0,sizeof(k));

    for(int i=0;i<1001;i++) dp[i][0] = dp[0][i] = 1e9;

    int T; cin>>T;
    while(T--){
        cin>>n>>m;
        int num;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> num;
                if(k[num]==0) solve(num);
                if(i==1 && j==1)
                    dp[i][j] = k[num];
                else dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + k[num];
            }
        }
        cout << dp[n][m] << '\n';
    }

    return 0;
}
