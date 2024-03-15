#include <bits/stdc++.h>
using namespace std;
#define endll "\n"
typedef long long ll;
typedef double db;  

bool isNug[105];
int n; 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    isNug[0]=1;

    if(n<6)
    {
        cout << "no";
        return 0;
    }
    //cout<< isNug[-1];

    for(int i=6;i<=n;i++)
    {
        if(isNug[i-6]||isNug[i-9]||isNug[i-20])
        {

            cout << i << endll;
            isNug[i]=1;
        }
    }

    return 0;

}