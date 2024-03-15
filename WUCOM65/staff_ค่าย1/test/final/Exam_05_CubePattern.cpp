#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin>>n;
    for(int i=1;i<=2*n-1;i++){
        for(int j=1;j<=2*n-1;j++){
            if(j<=n) 
            {
                if(i == 2*n-1 || i==n || (i>n && (j==1||j==n)))
                    cout << "*";                
                else if(i<n && i+j == n+1)
                    cout << "*";
                else cout << "-";
            }
            else if(i<n && i+j == 2*n)
                cout << "*";
            else if(i==1) cout << "*";
            else if(j==2*n-1 && i <=n) cout << "*";
            else if(i+j == n*3-1) cout << "*";
            else if(i+j >= n*3) cout << "";
            else cout << "-";
        } cout << "\n";
    }

    return 0;
}