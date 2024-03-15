#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int K;cin>>K;
    int a[K],b[K];
    for(int i=0;i<K;i++) 
        cin>>a[i];
    for(int i=0;i<K;i++)
        cin>>b[i];
    sort(a,a+K); 
    sort(b,b+K);
    int sum=0;
    for(int i=0;i<K;i++){
        sum+=abs(a[i]-b[i]);
    }
    cout << sum;

    return 0;
}