#include<bits/stdc++.h>
using namespace std;
int ans=0;

void mergesort(int arr[],int l,int r)
{
    if(l<r){
        int m=(l+r)>>1;

        mergesort(arr,l,m);
        mergesort(arr,m+1,r);

        int ls=m-l+1;
        int rs=r-m;
        int L[ls],R[rs];
        for(int i=0;i<ls;i++) L[i]=arr[l+i];
        for(int i=0;i<rs;i++) R[i]=arr[m+i+1];

        int i=0,j=0,k=l;
        while(i<ls && j<rs){
            if(L[i] <= R[j]){
                arr[k] = L[i];
                i++;
            }else {
                arr[k] = R[j];
                ans += m-i-l+1;
                j++;
            }
            k++;
        }
        while(i<ls){
            arr[k] = L[i];
            i++;
            k++;
        }
        while(j<rs){
            arr[k] = R[j];
            j++;
            k++;
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    mergesort(arr,0,n-1);

    /*
    for(int i=0;i<n;i++)
        cout<<arr[i]<< " ";
    */
    cout << ans;

    return 0;
}
/*
5
10
40
30
50
20
*/