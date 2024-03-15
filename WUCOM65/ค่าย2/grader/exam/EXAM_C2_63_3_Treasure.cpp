#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,s; cin>>n>>s;
    int l=0, r=n;
    while(l<r){
        int m=(l+r)>>1;
        
        int x=m,sum=0;
        while(x){   
            sum+=x%10;
            x/=10;
        }
        if(abs(m-sum) >= s) r=m;
        else l=m+1;

        if(l==n && abs(n-sum) < s){ 
            cout << "0\n-1"; return 0;
        }
    } 
    cout << n-l+1 << '\n' << n;

    return 0;
}