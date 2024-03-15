#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t=5;
    while(t--){
        int n; cin>>n;
        int l = floor(log10(n))+1;
        int sum=0;
        for(int i=1;i<=l;i++){
            sum+= pow((int)(n/pow(10,l-i))%10,i);
        }
        if(sum==n) cout << "Y";
        else cout << "N";
    } 

    return 0;
}