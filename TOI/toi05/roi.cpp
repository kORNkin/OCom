#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double K; cin>>K;
    double mn=DBL_MAX,a,b,c;
    for(int i=74;i<=144;i++){
        double sum;
        for(int j=1000;j<=15000;j+=500){
            sum=K;
            sum+= j * (100-((j-1000)/500));
            double x = ((100 - (0.8569 * exp(0.09*(i-100))))*j)/100;
            x*=i;
            if(x > sum && mn > x-sum){
                a=j; b=i; c=x-sum;
                mn=x-sum;
            }
        }
    }
    cout << a << "\n" << b << "\n";
    cout << fixed << setprecision(2) << c;

    return 0;
}