#include <bits/stdc++.h>
using namespace std;
int A,B,C;
bool ch=0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>A>>B>>C;
    for(int i=1;i<=100;i++){
        for(int j=i+1;j<=100;j++){
            for(int k=j+1;k<=100;k++){
                int c = i*i+j*j+k*k;
                if(c > C) break;
                int b = i*j*k;
                if(b > B) break;
                int a = i+j+k;
                if(a > A) break; 
                if(a == A && b==B && c==C) {
                    cout << i << " " << j << " " << k;
                    return 0;
                }
            }   
        }
    } cout << "No solution. ";

    return 0;
}