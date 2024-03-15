#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);

    long long L[51];
    L[0]=0;
    for(int i=1;i<=4;i++) {
        L[i]=1; 
        //cout<< i << " : "<< L[i] << '\n';
    }
    for(int i=5;i<51;i++){
        L[i] = L[i-1]+L[i-2]+L[i-3]+L[i-4];
        //cout<< i << " : "<< L[i] << '\n';
    }
    string start[] = {"L","O","V","E"};

    int T; cin>>T;
    while(T--){
        long long n,k; cin>>n>>k;
        long long idx=0;
        while(n>4){
           for(int i=4;i>=1;i--){
                idx+= L[n-i];
                if(idx >= k){
                    k = k- idx+ L[n-i];
                    n = n-i;
                    idx = 0;
                    cout << n << ' ' << k << '\n';
                    break;
                }
            } 
        }
        cout << n-1 << ' ';
        cout << start[n-1] << '\n';
        
    }

    return 0;
}
