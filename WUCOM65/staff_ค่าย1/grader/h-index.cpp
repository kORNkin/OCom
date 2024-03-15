#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int k; cin>>k;
    while(k--){
        int n; cin>>n;
        int num[n];
        for(int i=0;i<n;i++) cin>>num[i];
        sort(num,num+n,greater<int>());
        for(int i=num[0];i>=0;i--){
            for(int j=0;j<n;j++){
                if(i>=j && ((i+1 >= num[j-1] && )||()))
            }
        }
    }
    return 0;
} 

