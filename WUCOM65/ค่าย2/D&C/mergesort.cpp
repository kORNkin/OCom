#include <bits/stdc++.h>
using namespace std;
int arr[] = {3,5,4,8,2,1,6};

void msort(int l,int r){
    if(l>=r) return;
    int m = (l+r)>>1;

    msort(l,m);
    msort(m+1,r);

    int ls = m-l+1, rs = r-m;
    int L[ls],R[rs];

    for(int i=l;i<=m;i++) L[i-l] = arr[i];
    for(int i=m+1;i<=r;i++) R[i-m-1] = arr[i];

    int i=0,j=0,k=l;

    while(i < ls && j < rs){
        if(L[i] > R[j]){
            arr[k] = R[j];
            j++;
        }else {
            arr[k] = L[i];
            i++;
        } k++;
    }

    while(i < ls){
        arr[k] = L[i];
        k++; i++;
    }
    while(j < rs){
        arr[k] = R[j];
        k++; j++;
    }
}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    
    int n = sizeof(arr)/sizeof(arr[0]);
    msort(0,n-1);

    for(int i=0;i<n-1;i++){
        cout << arr[i] << ' ';
    }

    return 0;
}
