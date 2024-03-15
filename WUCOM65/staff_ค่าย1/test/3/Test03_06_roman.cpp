#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    string ans="";
    cin>>n;
    string rm1[]={"I","X","C","M"};
    string rm2[]={"V","L","D"};
    int dg =floor(log10(n))+1;
    for(int i=0;i<dg;i++){
        int x = n%10;
        n/=10;
        if(x<4){
            for(int j=0;j<x;j++)
                ans=rm1[i]+ans;            
        }else if(x==4)
        {
            string tmp = rm1[i]+rm2[i];
            ans=tmp+ans;
        }else if(x==9){
            string tmp = rm1[i]+rm1[i+1];
            ans=tmp+ans;
        }else{
            x-=5;
            for(int j=0;j<x;j++)
                ans=rm1[i]+ans;
            ans=rm2[i]+ans;           
        }
    }
    cout << ans;

    return 0;
}
