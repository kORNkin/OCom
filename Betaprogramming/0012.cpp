#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    cin>>s;
    int n=s.length();
    n=n*4+1;
    for(int i=0;i<5;i++){
        for(int j=0;j<n;j++){
            if(i==0 || i==4){
                if((j+2)%4==0 &&((j+2)/4)%3==0) cout<<"*";
                else if((j+2)%4==0) cout<<"#";
                else cout<<".";
            }else if(i==1 || i==3){
                int tmp = j+1;
                tmp/=2;
                if(((j+1)%2==0)&&((tmp+1)%6==0 || tmp%6==0)) cout<<"*";
                else if(((j+1)%2==0)) cout<<"#";
                else cout<<".";
            }else if(i==2){
                int tmp=j/4;
                if(j%4==0 && ((tmp+1)%3==0 || tmp%3==0) && j!=0 && (j!=n-1 || s.length()%3==0)) cout<<"*";
                else if(j%4==0) cout<<"#";
                else if(j%2==0) cout<<s[(j+2)/4-1];
                else cout<<".";
            }  
        } cout << "\n";
    }

    return 0;
}