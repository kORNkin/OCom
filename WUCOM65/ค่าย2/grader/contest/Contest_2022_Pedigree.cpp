#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin>>T;
    while(T--){
        int k,a; cin>>k>>a;
        int R[k-1]; for(auto &x:R) cin>>x;
        int sum=0;
        sum+= pow(2,k-1)*a;
        int x = pow(2,k-2);
        for(int i=0;i<k-1;i++){
            sum-= x*R[i];
        }
        if(sum<=0) {
            cout << "-1\n"; continue;
        }
        sum+= x*(k-1);
        cout << sum << '\n';
    }

    return 0;
}