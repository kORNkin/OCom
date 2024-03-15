#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;
    double cnt=0,arr[]={1.00,0.75,0.50,0.25,0.125};
    while(n--){
        int x;
        for(int i=0;i<5;i++)
            cin>>x,cnt+=x*arr[i];
    }
    cout << ceil(cnt);

    return 0;
}