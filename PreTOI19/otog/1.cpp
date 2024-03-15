#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long n;
    cin >>n;
    string bi =" ";
    while(n){
        char tmp = (n%2+'0');
        bi = tmp+bi;
        n/=2;
    }
    cout << bi;


    return 0;
}

