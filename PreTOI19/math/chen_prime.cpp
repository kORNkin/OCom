#include<bits/stdc++.h>
using namespace std;
#define max 20000001 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<bool> pm(max);
    fill(pm.begin(),pm.end(),1);
    for(int i=2;i<max;i++){
        if(pm[i]){
            for(int j=i+i;j<max;j+=i)
                pm[j]=0;
        }
    }
    int a,b,co=0;
    cin>>a>>b;
    for(int k=a;k<=b;k++){
        if(pm[k]){
            int i=k+2;
            if(pm[i]) co++;
            else {
                for(int j=2;j*j<=i;j++){
                    if(i%j==0 && pm[j] && pm[i/j]){
                        co++;
                        break;
                    }
                }
            }
        }
    }
    cout << co;
    return 0;
}