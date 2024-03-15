#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n[9],sum=0;
    for(int i=0;i<9;i++){
        cin>>n[i]; 
        sum+=n[i];
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(sum-n[i]-n[j]==100){
                for(int k=0;k<9;k++){
                    if(k!=i && k!=j)
                        cout<<n[k]<<"\n";
                }
                return 0;
            }
        }
    }

    return 0;
}