#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

    int a,b; cin>>a>>b;

    bool num[b+1];
    memset(num,0,sizeof(num));
    for(int i=2;i<3000;i++){
        for(int j=2;j<3000;j++){
            long long n = pow(i,2)*pow(j,3);
            if(n > b) break;
            num[n]=1;
        }
    }
    for(int i=2;i<30000;i++){
        for(int j=2;j<30;j++){
            long long n = pow(i,j);
            if(n > b) break;
            num[n]=0;
        }
    } 
    int cnt=0;
    for(int i=a;i<=b;i++){
        if(num[i]) 
        {
            cnt++; 
        }
    } 
    cout << cnt;
    
    return 0;
}