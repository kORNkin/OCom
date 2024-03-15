#include<bits/stdc++.h>
using namespace std;
bool notP[2000001];
vector<int> prime;
void primeSieve(){
    memset(notP,0,sizeof(notP));
    for(int i=4;i<2000001;i+=2)
        notP[i]=1;
    for(int i=3;i<2000001;i+=2){
        if(!notP[i]){
            prime.push_back(i);
            for(int j=i+i;j<2000001;j+=i)
                notP[j]=1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin>>t;
    primeSieve();
    while(t--){
        int n; cin>>n;
        while(n%2==0){
            n/=2;
        }
        int sum=1;
        for(auto p:prime){
            if(p > n) break;
            int cnt=0;
            while(n%p==0){
                n/=p;
                cnt++;
            }
            sum*=cnt+1;
        }
        cout << sum-1 << '\n';
        
    }
    
    return 0;
}