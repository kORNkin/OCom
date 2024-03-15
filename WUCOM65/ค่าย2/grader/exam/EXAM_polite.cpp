#include<bits/stdc++.h>
using namespace std;
double x;
bool polite(int n){
    if(n<=2) return 0;
    if(n%2!=0) return 1;
    
    x = log2(n);
    return x!=floor(x);
}

vector<int> pts;
bool isPts[500001];
void memPolite(){
    memset(isPts,0,sizeof(isPts));
    for(int i=0;i<500001;i++){
        if(polite(i)){
           pts.push_back(i); 
           isPts[i]=1;;
        } 
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memPolite();

    int t; cin>>t;
    while(t--){
        int n,cnt=0; cin>>n;
        int x=0;
        while(pts[x]<=n/2){
            if(isPts[n-pts[x]]) cnt++;
            x++;
        }
        cout << cnt << '\n';
    }

    return 0;
}

