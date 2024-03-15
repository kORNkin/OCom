#include<bits/stdc++.h>
using namespace std;
int n;
long long sum=0;
pair<long long,long long> arr[100001]; 
long long qs[100001];
void msort(int l,int r){
    if(l >= r) return;
    int m = (l+r)>>1;
    msort(l, m), msort(m+1, r);
    qs[0]=0;
    int ls = m-l+1, rs = r-m;
    pair<long long, long long> L[ls],R[rs];
    for(int i = l; i <= m; i++) 
        L[i-l] = arr[i], qs[i-l] = arr[i].first + (i==0?0:qs[i-l-1]);
    for(int i = m+1; i <=r ; i++) 
        R[i-m-1] = arr[i];
    int i = 0, j = 0, k = l;
    while(i < ls && j < rs){
        if(L[i].second > R[j].second){
            arr[k] = R[j];
            j++;
            sum += qs[ls-1]-qs[i-1] + (arr[k].first * (ls-i));
        }else {
            arr[k] = L[i];
            i++;
        } k++;
    }
    while(i < ls){
        arr[k] = L[i];
        k++, i++;
    }
    while(j < rs){
        arr[k] = R[j];
        k++, j++;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) 
        cin >> arr[i].first >> arr[i].second;    
    sort(arr,arr+n);
    msort(0,n-1);
    cout << sum;
    return 0;
}