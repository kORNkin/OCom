#include<stdio.h>
int arr[]={1,3,4,6,7,9,11,12,20,100};
int n; 
int bs(int l,int r){
    if(l==r) {
        if(arr[l]==n) return l+1;
        return -1;
    }
    int m = (l+r) >> 1;

    if(n <= arr[m]) return bs(l,m);
    else return bs(m+1,r); 
}
int main ()
{
    scanf("%d",&n);
    printf("%d",bs(0,9));

    return 0;
}