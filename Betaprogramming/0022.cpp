#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,k; cin>>n;
    n%2==0 ? k=n-1 : k=n;
    for(int i=0; i<=k/2;i++){
        for(int j=1;j<=k;j++){
            if(j==k/2+1-i || j==k/2+1+i)  {
                cout << "*";
            }
            else cout << "-";
        } cout << "\n";
    }
    for(int i=0;i<n/2;i++){
        for(int j=1;j<=k;j++){
            if(j==k/2+n/2-i || j==k/2-n/2+i+2)  {
                cout << "*";
            }
            else cout << "-";
        } cout << "\n";
    }

    return 0;
}