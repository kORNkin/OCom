#include<bits/stdc++.h>
using namespace std;
bool notP[300001];
vector<int> prime;
void PrimeSieve(){
    memset(notP,0,sizeof(notP));
    prime.emplace_back(2);
    notP[0]=1;
    notP[1]=1;
    for(int i=4;i<300001;i+=2)
        notP[i]=1;
    for(int i=3;i<300001;i+=2){
        if(!notP[i]){
            prime.emplace_back(i);
            for(int j=i+i;j<300001;j+=i)
                notP[j]=1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    PrimeSieve();

    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        int cnt=0;
        for(auto x:prime){
            if(x>n/2) break;
            if(!notP[n-x]){
                cnt++;
            }
        } cout << cnt << '\n';
    }

    return 0;
}