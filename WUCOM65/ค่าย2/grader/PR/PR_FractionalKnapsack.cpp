#include<bits/stdc++.h>
using namespace std;
struct Knapstack{
    double v,w;    
    bool operator < (const Knapstack &a){
        if(v/w == a.v/a.w) return w < a.w;
        return v/w > a.v/a.w;
    } 
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin>>T;
    while(T--){
        int n,w; cin>>n>>w;
        Knapstack arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i].v>>arr[i].w;
        }
        sort(arr,arr+n);
        double val=0;
        for(int i=0;i<n;i++){
            if(w-arr[i].w < 0){
                val += w*(arr[i].v/arr[i].w);
                break;
            }else {
                w-=arr[i].w;
                val += arr[i].v;
            }
        } cout << fixed << setprecision(2) << val << '\n';
    }
    
    return 0;
}