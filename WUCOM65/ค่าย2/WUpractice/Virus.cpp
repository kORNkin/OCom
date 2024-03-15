#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin>>s;
    int n; cin>>n;
    string arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n , greater<string>());

    int cnt[n]; memset(cnt,0,sizeof(cnt));
    int mx=0,idx=0, smx=1e9;

    for(int i=0;i<n;i++){
        for(int j=0;j<s.size();j++){
            if(s[j] == arr[i][0]){
                bool ch=0;
                int k;
                for(k=j+1;k<j+arr[i].size() && k<s.size();k++){
                    if(s[k] != arr[i][k-j]){
                        ch=1;
                        break;
                    }
                }
                if(!ch && k-j==arr[i].size()) cnt[i]++ , j=k;
            }
        }
        if(mx <= cnt[i]  ) {
            if(mx == cnt[i] && smx < arr[i].size()) continue;
            smx = arr[i].size();
            mx=cnt[i], idx=i;
        }
    }
    cout << arr[idx];

    return 0;
}