#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,m,k=-1;
    cin>>n>>m;
    string a,b;
    cin>>a;
    for(int i=1;i<m;i++){
        cin>>b;
        int co=0;
        for(int j=0;j<n && k==-1 ;j++)
        {
            if(a[j]!=b[j])
                co++;
            if(co>2){
                cout << a;
                return 0;
            }
        }
        a=b;
    }  
    cout << a;

    return 0; 
}