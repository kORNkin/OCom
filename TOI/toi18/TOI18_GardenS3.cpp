#include<bits/stdc++.h>
using namespace std;
vector<int> h;  
int n,q,mx=0,imx;
int bs(int l,int r,int x)
{
    if(l==r) return l;
    int m=(l+r)>>1;
    if(h[m]>h[x])
        return bs(l,m,x);
    else return bs(m+1,r,x);
}
int bs_rev(int l,int r,int x)
{
    if(l==r) return l;
    int m=(l+r)>>1;
    if(h[m]<h[x])
        return bs_rev(l,m,x);
    else return bs_rev(m+1,r,x);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int x;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>x;
        h.push_back(x);
        if(mx<x){
            mx=x; imx=i;
        }
    }
    while(q--){
        cin>>x;
        if(imx==n-1 || imx==0 || x==0 || x==n-1 || h[x]<h[0] || h[x]<h[n-1]){
            cout<<"0\n"; continue;
        }else if(x==imx){
            cout<<min(x,n-imx-1)<<"\n";
            continue;
        }
        int k;
        if(x>imx){
            k=bs(0,imx-1,x);
            //cout<<"bs:"<<k<<"\n";
            if(h[k]>h[x]) k--;
            k=min(k+1,n-x-1);
        }else {
            k=bs_rev(imx+1,n-1,x);
            //cout<<"bs:"<<k<<"\n";
            k=min(n-k,x);
        } cout<<k<<"\n";
    } 

    return 0;
}
/*
11 11
1 3 5 7 9 110 13 12 10 8 6
0 1 2 3 4 5 6 7 8 9 10

8 8
7 9 12 14 11 10 8 6
0 1 2 3 4 5 6 7 

8 8
7 9 11 12 14 13 8 6
0 1 2 3 4 5 6 7
*/
