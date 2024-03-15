#include<bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    set<int> c;
    int cnt[101]; memset(cnt,0,sizeof(cnt));
    while(n--){
        int x; cin>>x;
        cnt[x]++;
        c.insert(x);
    }
    cin >> n;
    while(n--){
        int x; cin>>x;
        cnt[x]++;
        c.insert(x);
    }
    bool ch=0;
    for(auto n:c){
        if(cnt[n]>1){
            cout << n << ' ';
            ch=1;
        }
    } cout << '\n'; 
    if(!ch) cout << "-1\n";
    ch=0;
    for(auto n:c){
        if(cnt[n]==1){
            cout << n << ' ';
            ch=1;
        }
    } cout << '\n'; 
    if(!ch) cout << "-1\n";
    for(auto n:c) cout << n << ' ';
    cout << '\n';

    return 0;
}