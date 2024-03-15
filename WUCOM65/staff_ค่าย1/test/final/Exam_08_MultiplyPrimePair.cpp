#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; 
    cin>>t;
    int p[100001];
    memset(p,0,sizeof(p));
    for(int i=2;i<=50000;i++){
        if(p[i]==0){  
            p[i]=1;                
            for(int j=i*2;j<=50000;j+=i){
                p[j]=2;          
            }           
        }
    }
    //cout << p[t];
    while(t--){
        int n;
        cin>>n;
        n--;
        while(++n){
            for(int i=2;i<=sqrt(100000);i++){
                if(n%i!=0) continue;
                if(p[i]==1 && p[n/i]==1 && i!=n/i){
                    cout << n << "\n";
                    n=-1;
                    break;
                }
            }
        }
    }

    return 0;
}
/*
20
123 21235 344 42 51 6646 7456 8456 91 10111 11231 1222 13134 142 152 160 1700 1811 19213 20222
*/