#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) 
      cin >> arr[i]; 
    int sumx = 0, mn = 10001;
    for(int i = 0; i < n; i++){
        mn = min( mn, arr[i] );
        sumx = max( sumx, arr[i]-mn );
    }
    cout << sumx;

    return 0;
}
