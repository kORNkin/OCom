#include<bits/stdc++.h>
using namespace std;
int m,o,mx=0,summ=0;
int arr[101];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>o;
    for(int i=0;i<o;i++) 
        cin>>arr[i], mx = max(mx,arr[i]), summ+=arr[i];
    int l=mx, r=summ;
    while(l<r){
        int mid = (l+r)/2;

        int sum=0,cnt=0;
        for(int i=0;i<o;i++){ 
            sum+=arr[i];     
            if(sum > mid){
                cnt++;
                sum=arr[i];
            }
        } 
        if(cnt>=m) l = mid+1;
        else r = mid;
        
    } cout << l ;
    
    return 0;
}