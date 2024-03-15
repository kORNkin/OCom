#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m; cin>>m>>n;
    string a,b; cin>>a>>b;
    int mem[256];
    for(int i='A';i<='Z';i++){
        int sum=i;
        int x[3];
        for(int j=0;j<m;j++){
            x[0]=a[j]; x[1]=b[j]; x[2]=sum;
            sort(x,x+3);
            sum = x[1];
        }
        mem[i]=sum;
    }
    cin>>a;
    for(auto c:a){
        cout << (char)mem[c];
    }

    return 0;
}