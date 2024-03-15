#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    if(n==0) {
        cout<<0;
        return 0;
    }
    string oct="";
    while(n>0){
        char tmp = n%8 +'0';
        oct=tmp+oct;
        n/=8;
    }
    cout << oct;
    return 0;
} 

