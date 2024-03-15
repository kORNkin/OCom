#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);

    long long L[51];
    L[0]=0;
    for(int i = 1; i <= 2; i++) 
        L[i] = 1; 
    
    for(int i = 3; i < 51; i++)
        L[i] = L[i-1] + L[i-2];
    
    string iluvyou[] = {"A","B"};

    int T; cin >> T;
    while(T--){
        long long n,k; cin >> n >> k;
        long long idx = 0;
        while(n > 2){
           for(int i = 2; i >= 1; i--){
                idx += L[n-i];
                if(idx >= k){
                    k = k - idx + L[n-i];
                    n = n - i;
                    idx = 0;
                    break;
                }
            } 
        }
        cout << iluvyou[n-1] << '\n';
    }

    return 0;
}