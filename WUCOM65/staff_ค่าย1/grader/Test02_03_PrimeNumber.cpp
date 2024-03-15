#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,co=1; cin>>n;
    if(n==2){
        cout << "2\n1"; return 0;
    }
    cout << "2 ";
    for(int i=3;i<=n;i++){
        int ch=0;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                ch=1; break;
            }
        }
        if(!ch) {
            cout << i << " "; co++;
        }
    }
    cout <<"\n"<<co;
    return 0;
} 

