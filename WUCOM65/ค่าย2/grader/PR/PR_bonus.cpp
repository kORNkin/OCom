#include<bits/stdc++.h>
using namespace std;
struct homework{
    long long int dl,bns;
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    homework arr[n];
    for(int i=0;i<n;i++){
        int dl,bns; cin>>dl>>bns;
        arr[i].dl = dl;
        arr[i].bns = bns;
    }
    sort(arr,arr+n, [&](homework &a,homework &b){
        if(a.bns == b.bns) return a.dl < b.dl;
        return a.bns > b.bns;
    });
    long long int tm=0,sum=0,mx=0;
    for(int i=0;i<n;i++){
        if(tm < arr[i].dl){
            sum+=arr[i].bns;
            tm++;
        }
    } mx=sum;
    tm=0; sum=0;
    sort(arr,arr+n, [&](homework &a,homework &b){
        if(a.dl == b.dl) return a.bns > b.bns;
        return a.dl < b.dl;
    });
    for(int i=0;i<n;i++){
        if(tm < arr[i].dl){
            sum+=arr[i].bns;
            tm++;
        }
    }
    
    cout << max(mx,sum);

    return 0;
}