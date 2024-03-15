#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,m; cin>>n>>m;
    int arr[n];
    for(int &x:arr) cin>>x;
    sort(arr,arr+n);
    while(m--){
        int x; cin>>x;
        int a=0,b=n-1;
        bool ch=0;
        while(a<b){
            int sum = arr[a]+arr[b];
            if(sum==x){
                ch=1;
                break;
            }else if(sum < x){
                a++;
            }else if(sum > x){
                b--;
            }
        }
        if(ch) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}