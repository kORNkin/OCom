#include<bits/stdc++.h>
using namespace std;
struct Time{
    int h,m,s;
    int k;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    vector<Time> tm;
    while(n--){
        string a,b; cin>>a>>b;
        int t[3],k=0;
        t[0]=0; t[1]=0; t[2]=0;
        bool r=1;
        for(int i=0;i<a.size();i++){
            if(a[i]!=':'){
                t[k]+=(a[i]-'0')*pow(10,r);
                r=0;
            }else{
                r=1;
                k++;
            }
        }
        tm.push_back({t[0],t[1],t[2],1});
        t[0]=0; t[1]=0; t[2]=0; k=0; r=1;
        for(int i=0;i<b.size();i++){
            if(b[i]!=':'){
                t[k]+=(b[i]-'0')*pow(10,r);
                r=0;
            }else{
                r=1;
                k++;
            }
        }
        tm.push_back({t[0],t[1],t[2],-1});
    }
    sort(tm.begin(),tm.end(),[&](Time a, Time b){
        if(a.h == b.h){
            if(a.m == b.m){
                if(a.s == b.s)
                    return a.k < b.k;
                return a.s < b.s;
            }
            return a.m < b.m;
        } return a.h < b.h;
    });

    int cnt=0,mx=0;
    for(auto t:tm){
        //cout << t.h << ":" << t.m << ":" << t.s << " " << t.k << '\n';
        cnt += t.k;
        mx = max(mx,cnt);
    } cout << mx;

    return 0;
}