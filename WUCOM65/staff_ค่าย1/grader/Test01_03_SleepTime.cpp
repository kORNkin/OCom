#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int k; cin>>k;
    while(k--){
        double a,b;
        cin>>a>>b;
        int h1,h2;
        int m1,m2;
        h1 = int(a*100)/100;
        h2 = int(b*100)/100;
        m1 = int(a*100) %100;
        m2 = int(b*100) %100;
        int sumh=0,summ=0;
        if(h1>h2){           
            if(m1>0){
                h1++;
                summ = 60-m1;
            }
            summ+=m2;
            sumh = 24-h1 + h2 + (summ/60);
            summ%=60;
            printf("%d:%02d\n",sumh,summ);
        }
        else if(h1==h2 ){
            if(m1==m2)
                cout<<"24:00\n";
            else if(m2<m1)
                printf("23:%02d\n",60-(m1-m2));
            else printf("00:%02d\n",m2-m1);
        }else {
            if(m1>m2){
                summ = m2+60-m1;
                h2--;
            }else summ = m2-m1;
            sumh = h2-h1;
            printf("%d:%02d\n",sumh,summ);
        }
    }
    return 0;
} 
/*16
5.52 7.55
15.13 17.23
16.05 16.11
1.11 17.01
18.51 20.00
17.37 6.06
14.53 14.29
23.17 18.52
3.19 4.49
8.09 21.03
18.46 3.33
0.07 15.10
0.44 7.36
15.13 23.50
8.21 22.58
17.22 11.17*/
