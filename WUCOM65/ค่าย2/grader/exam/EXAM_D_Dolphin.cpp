#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin>>T;
    while(T--){
        long long int n,i=0; cin>>n;
        if(n<=3) {
            if(n==1) cout << "1 dolphin\n";
            else if(n==2) cout << "1 jump\n";
            else cout << "splash\n";
            continue;
        }

        while(++i)
            if(3*i*(i+1)/2 >= n) break;   

        double x = n-3*i*(i-1)/2;
        x = ceil(x/i);
        
        string dlp[] = {"dolphins\n","jumps\n"};
        if(x==3) cout << "splash\n";
        else cout << i << " " << dlp[(long long int)x-1];
        
    }

    return 0;
}