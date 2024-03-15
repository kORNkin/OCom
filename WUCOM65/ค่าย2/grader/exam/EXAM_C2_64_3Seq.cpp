#include<bits/stdc++.h>
using namespace std;
struct Num{
    int val;
    bool ch;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;
    int mxx = INT_MIN;
    vector<Num> mem[n];
    for(int i=0;i<n;i++){
        int x; cin>>x;
        mxx= max(mxx,x);
        mem[i].push_back({x,0});
        for(int j=i-1;j>=0;j--){
            int mx= INT_MIN;
            bool ch=0;
            for(auto e:mem[j]){
                if(mx >= e.val+x) continue;
                if(j==i-1) {
                    if(e.ch) continue;
                    ch=1;
                }
                else ch=0;
                mx = e.val+x;
            }
            mxx = max(mxx,mx);
            mem[i].push_back({mx,ch});
        }
    } cout << mxx;
    
    return 0;
}