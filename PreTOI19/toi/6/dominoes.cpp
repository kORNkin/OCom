#include<bits/stdc++.h>
using namespace std;
int n;
void solve(int x,string s)
{
    if(x>n) return;
    if(x==n){
        cout <<s<< "E\n";
        return;
    }
    solve(x+1,s+"--\n");
    solve(x+2,s+"||\n");
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    solve(0,"");

    return 0;
}