#include<bits/stdc++.h>
using namespace std;
int n;
int arr[100001];

void msort(int l,int r){
    if(l>=r) return;

    int m = (l+r) >> 1;
    msort(l,m);
    msort(m+1,r);

    int ls=m-l+1 , rs=r-m;
    int L[ls], R[rs];
    for(int i=l;i<=m;i++) L[i-l] = arr[i];
    for(int i=m+1;i<=r;i++) R[i-m-1] = arr[i];

    int i=0,j=0,k=l;

    while(i<ls && j<rs){
        if(L[i] > R[j]){
            arr[k] = R[j];
            j++;
        }else {
            arr[k] = L[i];
            i++;
        } k++;
    }
    while(i<ls){
        arr[k] = L[i];
        i++; k++;
    }

    while(j<rs){
        arr[k] = R[j];
        j++; k++;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];

    msort(0,n-1);

    for(int i=0;i<n;i++) cout<<arr[i]<<' ';

    return 0; 
}