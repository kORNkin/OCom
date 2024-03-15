#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
long long arr[N];
long long qs[350][N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,q; cin>>n>>q;
    int mxn = sqrt(n)+1;
    for(int i=1;i<=n;i++) cin>>arr[i];

    for(int i=1;i<=mxn;i++){
        for(int j=1;j<=n;j++){
            qs[i][j] = qs[i][max(0,j-i)]+arr[j];
        }
    }
    while(q--){
        long long l,m,r; cin>>l>>m>>r;
        if(m<=mxn){
            r = ((r-l)/m)*m + l;
            cout << qs[m][r]- qs[m][max(0ll, l-m)] << ' ';
        }else {
            int sum=0; 
            for(int i=l;i<=r;i+=m) sum+=arr[i];
            cout << sum << ' ';
        }
    }

    return 0;
}