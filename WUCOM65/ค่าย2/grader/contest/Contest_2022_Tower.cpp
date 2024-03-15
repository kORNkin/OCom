#include<bits/stdc++.h>
using namespace std;
pair<int,int> arr[100001];
int cnt[1000001];
int n;
void msort(int l,int r){
    if(l>=r) return; 
    int m=(l+r)>>1;

    msort(l,m);
    msort(m+1,r);

    int ls = m-l+1;
    int rs = r-m;
    pair<int,int> L[ls],R[rs];
    cout << "L :";
    for(int i=l;i<=m;i++) 
    {
        L[i-l].first = arr[i].first;
        L[i-l].second = arr[i].second;
    } 
    for(int i=m+1;i<=r;i++)
    {
       R[i-m-1].first = arr[i].first; 
       R[i-m-1].second = arr[i].second;
    } 
    
    int i=0,j=0,k=l;
    while(i<ls && j<rs){
        if(L[i] <= R[j]){
            arr[k].first = L[i].first;    
            arr[k].second = L[i].second;  
            i++;
        }else {
            arr[k].first = R[j].first;
            arr[k].second = R[j].second;  
            
            cnt[R[j].second]+=i;
            j++;
        } k++;
    }
    while(i<ls){
        arr[k].first = L[i].first;
        arr[k].second = L[i].second;  
         i++; k++;     
    }
    while(j<rs){
        arr[k].first = R[j].first;
        arr[k].second = R[j].second;  
        cnt[R[j].second]+=ls; 
        j++; k++;
       
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
        arr[i].second = i;    
    }
    
    memset(cnt,0,sizeof(cnt));
    msort(0,n-1);

    for(int i=0;i<n;i++)
        cout<< cnt[i] << ' ';
    

    return 0;
}
/*
8
2 4 5 4 1 8 3 7
L :2 
R :4 
0 1 0 0 0 0 0 0 
l: 0 m: 0 r: 1
--------
L :5 
R :4 
0 1 0 0 0 0 0 0 
l: 2 m: 2 r: 3
--------
L :2 4 
R :4 5 
0 1 2 2 0 0 0 0 
l: 0 m: 1 r: 3
--------
L :1 
R :8 
0 1 2 2 0 1 0 0 
l: 4 m: 4 r: 5
--------
L :3 
R :7 
0 1 2 2 0 1 0 1 
l: 6 m: 6 r: 7
--------
L :1 8 
R :3 7 
0 1 2 2 0 1 1 2 
l: 4 m: 5 r: 7
--------
L :2 4 4 5 
R :1 3 7 8 
0 1 2 2 0 2 5 6
l: 0 m: 3 r: 7
--------
0 1 2 2 0 2 5 6
*/