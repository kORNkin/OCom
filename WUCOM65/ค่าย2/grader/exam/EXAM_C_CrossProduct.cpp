#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int u[3],v[3];
    for(auto &x:u) cin>>x;
    for(auto &x:v) cin>>x;
    cout << u[1]*v[2]-u[2]*v[1] << " " << u[2]*v[0]-u[0]*v[2] << " " << u[0]*v[1]-u[1]*v[0];

    return 0;
}