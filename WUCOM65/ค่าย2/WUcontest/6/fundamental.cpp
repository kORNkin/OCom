#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

vector<int> prime;
bool notP[100001];
void P(){
    prime.emplace_back(2);
    int i,j;
    for(i=4;i<100001;i+=2){
        notP[i] = 1;
    }
    for(i=3;i<100001;i+=2){
        if(!notP[i]){
            prime.emplace_back(i);
            for(j=i+i;j<100001;j+=i){
                notP[j]=1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    P();
    int n; cin>>n;
    long long x,co,i;
    bool ch;
    while(n--){
        co=0; cin>>x;
        ch=0;
        if(x < 100001 && !notP[x]) {
            cout << "1\n";
            continue;
        }
        if(pow(2,floor(log2(x))) == x) {
            cout << log2(x) << '\n';
            continue;
        }
        for(i=0;i<prime.size();i++){   
            int p = prime[i];           
            if(x==1 || p > x) break;
            while(x%p == 0){
                co++;
                x/=p;
                ch=0;
            }  
            ch=0;               
            if(x==1) ch=1;            
            for(int j=i+1;prime[j]*prime[j]<=x && x!=1;j++){
                if(x%prime[j]==0){
                    ch=1;
                    x/=prime[j];                            
                    co++;
                    break;
                }       
            }
            if(!ch && x!=1) {
                cout << co+1 << '\n';
                break;
            }
        } if(ch) cout << co << '\n';
    }
    return 0;
}