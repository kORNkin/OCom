#include<bits/stdc++.h>
using namespace std;

int main()
{
    int sum=0;
    for(int k=1;k<=16;k*=2){
        int cnt=0;
        cout << "Do your birthday in this table?\n";
        for(int i=1;i<=31;i++){
            if((i&k) == k){
                cout << i << ' ';
                cnt++;
                if(cnt%5==0) cout << '\n';
            } 
        } 
        cout << "\n(Y/N) : ";
        char c; cin>>c;
        if(c=='Y' || c=='y') sum+=k;
        cout << "\n\n";
    }
    cout << "Your birthday is: " << sum; 

    return 0;
}