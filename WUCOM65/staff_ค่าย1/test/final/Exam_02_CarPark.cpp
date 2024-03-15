#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(d<b){
        d+=60;
        c--;
    }
    a = c-a;
    b = d-b;
    if((a==0 && b<=15)){
        cout << 0;
        return 0;
    }
    if((b>0 && a>0)|| (a==0 && b>15)) a++;
    int sum=0;
    if(a>6){
        cout << 200;
        return 0;
    }
    if(a>=4 && a<=6)
    {
        sum+=(a-3)*20;
        a=3;
    }
    if(a<=3){
        sum+=a*10;
        
    }
    cout << sum;

    return 0;
}