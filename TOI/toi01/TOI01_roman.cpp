#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
int cnt[5]; 
void cntRoman(int n){
    string ans="";
    string rm1[]={"I","X","C"};
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
    
    char rm[]={'I','V','X','L','C'};
    for(auto c:ans){
        for(int i=0;i<5;i++)
            if(c==rm[i]) cnt[i]++;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(cnt,0,sizeof(cnt));
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cntRoman(i);
    }
    for(auto x:cnt) cout << x << " ";

    return 0;
}
