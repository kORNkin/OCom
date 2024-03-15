#include <bits/stdc++.h>
using namespace std;
#define endll "\n"
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    char c; cin >> c;
    int n,m,i,j,k,l; cin >> n >> m;
    int b=2*n+1;

    for(k=1;k<=b*m;k++)
    {
        for(l=1;l<=b*m;l++)
        {
            i=k%b;
            j=l%b; 
            if(k%b==0) i++;
            if(l%b==0) j++;
            if(k==l||l==b*m-k+1) cout << "#";
            else if(i==j||j==b-i+1||i==n+1||j==n+1) cout << "+";
            else if(i+j>n+1 && j-i<=n && i-j<=n && i+j<=n*3+2) cout << c;
            else cout << ".";
        }
        cout << endll;
    }

    return 0;

}