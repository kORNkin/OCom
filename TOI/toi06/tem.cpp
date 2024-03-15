#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>v(100001,0);
void update(int idx){
    while(idx<=100001){
        v[idx]+=1;
        idx+=idx &(-idx);
    }
}
void gs(int idx){ 
    while(idx>0){
        cout<<v[idx];
        idx-=idx &(-idx);
    }
    
}
int main(){
    cin>>n>>m;
    update(n);
    gs(m);
}