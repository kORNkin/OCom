#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int num[]={1,2,3,4,5,6,7,8,9,0};
    int k; cin>>k;
    for(int i=1;i<=k;i++){
        int n=0;
        for(int j=1;j<=k*2-1;j++){
            if(i+j>k && j-i<k) 
            {
                cout << num[n%10];
                if(j<k)n++;
                else n--;
            }
            else cout << " ";
        }
        cout << "\n";
    }
    

    return 0;
} 

