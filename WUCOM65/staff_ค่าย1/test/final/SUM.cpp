#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    unsigned long long n,sum=0;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        sum+=x;
    } cout << sum;

    return 0;
}