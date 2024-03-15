/*
Author: kornkin.png
Algor:  Binary Search
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,i,a,b;
int po_qs[500010];
int ne_qs[500010];

void bs(int l,int r,int x)
{
    //cout << l << "  "<< r << " " << x << "\n";
    if(l>n || r>n){
        i=n-1;
        return;
    }
    if(l<0 || l>r){
        i=-1;
        return;
    }
    if(l==r){
        i=l;
        return;
    }
    int m=floor((l+r)/2);
    if(ne_qs[m]-ne_qs[a]<x){
        bs(m+1,r,x);
    }else {
        bs(l,m,x);
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    a=b=0;
    for(i=1;i<=n;i++){
        int x;cin>>x;
        if(x<0){
            a+=x;
            ne_qs[i]=-a;
            po_qs[i]=b;
        }else {
            b+=x;
            po_qs[i]=b;
            ne_qs[i]=-a;
        }
    }
    /*for(i=0;i<n;i++)
        cout << po_qs[i] << " ";
    cout<<"\n";
    for(i=0;i<n;i++)
        cout << ne_qs[i] << " ";
    cout<<"\n";*/
    while(m--){
        cin>>a>>b;
        bs(a+1,n,b);
        if(i==-1)
            cout << 0 << "\n";
        else cout << po_qs[i]-po_qs[a] << "\n";
    }

    return 0;
}