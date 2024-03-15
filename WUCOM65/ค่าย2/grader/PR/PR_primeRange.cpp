#include<bits/stdc++.h>
using namespace std;
bool notP[10001];
void PrimeSieve(){
    memset(notP,0,sizeof(notP));
    notP[0]=1;
    notP[1]=1;
    for(int i=4;i<10001;i+=2)
        notP[i]=1;
    for(int i=3;i<10001;i+=2){
        if(!notP[i]){
            for(int j=i+i;j<10001;j+=i)
                notP[j]=1;
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    PrimeSieve();
    int a,b; cin>>a>>b;
    int cnt=0;
    for(int i=a;i<=b;i++)
        if(!notP[i]) cnt++;
    cout << cnt;

    return 0;
}