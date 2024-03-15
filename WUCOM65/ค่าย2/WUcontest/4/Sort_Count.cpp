#include<bits/stdc++.h>
using namespace std;
int arr[100001];
long long cnt;
void msort(int l, int r){
    if(l>=r) return;

    int m = (l+r) >> 1;

    msort(l,m), msort(m+1,r);

    int ls = m-l+1, rs = r-m;
    int L[ls], R[rs];
    for(int i=l;i<=m;i++) L[i-l] = arr[i];
    for(int i=m+1;i<=r;i++) R[i-m-1] = arr[i];

    int i=0, j=0, k=l;
    while(i<ls && j<rs){
        if(L[i] > R[j]){
            arr[k] = R[j];
            j++;
            cnt += ls-i;
        }else {
            arr[k] = L[i];
            i++;
        } k++;
    }

    while(i<ls){
        arr[k] = L[i];
        k++; i++;
    }
    while(j<rs){
        arr[k] = R[j];
        k++; j++;
    }
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);

    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];

    msort(0,n-1);
    cout << cnt;

    return 0;
}
