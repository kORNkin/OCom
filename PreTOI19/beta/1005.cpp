#include<bits/stdc++.h>
using namespace std;
int qs[2501];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    qs[0]=0;
    cin>>qs[1];
    int max_sum=-1e9,x,y;
    for(int i=2;i<=n;i++){
        cin>>x;
        qs[i]=qs[i-1]+x;
    }
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(qs[j]-qs[i] > max_sum){
                max_sum=qs[j]-qs[i];
                x=i; y=j;
            }
        }
    }
    if(max_sum<=0){
        cout<<"Empty sequence";
        return 0;
    }
    for(int i=x+1;i<=y;i++)
        cout<< qs[i]-qs[i-1] << " ";
    cout << "\n"<<max_sum;
    return 0;
}