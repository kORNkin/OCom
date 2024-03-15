/*TASK:
LANG: C++
AUTHOR: Supphakon Yimi
CENTER: WU
*/
#include <bits/stdc++.h>
using namespace std;
#define endll "\n"
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

bool cmp(int a,int b){
    return a>b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,sum=0;
    cin >> n;
    int a[n],b[n],h[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        cin >> b[i];
    sort(a,a+n,cmp);
    sort(b,b+n);

    for(int i=0;i<n;i++)
        h[i]=a[i]+b[i];
    
    sort(h,h+n,cmp);

    for(int i=0;i<n-1;i++) {
        sum+=h[i]-h[i+1];
    }
    cout << sum;
    return 0;

}