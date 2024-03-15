#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,m; cin>>n>>m;
    long long int arr[m];
    long long int cnt[n]; memset(cnt,0,sizeof(cnt));

    for(int i=0;i<m;i++) cin>>arr[i];
    sort(arr,arr+m);

    double sum=0;
    int i=0;
    while(i<m){
        for(int j=0;j<n;j++){
            cnt[j]+=arr[i];
            sum+=cnt[j];
            i++;
            if(i>=m) break;
        }
    }
    cout << fixed << setprecision(3) << sum/m;

    return 0;
}