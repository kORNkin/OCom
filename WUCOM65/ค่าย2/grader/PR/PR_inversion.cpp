#include <bits/stdc++.h>
using namespace std;

long long int cnt=0;
void msort(int l,int r,int arr[]){
    if(l>=r) return;
    int m = (l+r)>>1;

    msort(l,m,arr);
    msort(m+1,r,arr);

    int ls = m-l+1, rs = r-m;
    int L[ls],R[rs];

    for(int i=l;i<=m;i++) L[i-l] = arr[i];
    for(int i=m+1;i<=r;i++) R[i-m-1] = arr[i];

    int i=0,j=0,k=l;

    while(i < ls && j < rs){
        if(L[i] > R[j]){
            arr[k] = R[j];
            j++;
            cnt+= ls-i;
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
    
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    msort(0,n-1,arr);

    cout << cnt;

    return 0;
}