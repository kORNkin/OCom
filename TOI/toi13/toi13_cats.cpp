#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, arr[2000001], l, r;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        r = max(r, arr[i]);
    }
    while(l < r){
        ll m = (l + r) >> 1, ch = 0;

        for(int i = 0; i < n; i++){
            if(arr[i] <= m) continue;
            if(!ch) ch = arr[i];
            else if(ch == arr[i]) ch = 0;
            else break;
        }

        if(ch) l = m + 1;
        else r = m;
    }
    cout << l;

    return 0;
}
