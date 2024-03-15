#include <bits/stdc++.h>
using namespace std;
int n,m,N;
vector<pair<int,int>> v;
vector<pair<int,int>> ans;
bool vis[11];
void solve(int i,int k,int arr[]){
    if(k==n){
        int a=0,b=0;
        bool vis[10];
        memset(vis,0,sizeof(vis));
        for(int l=0;l<5;l++){
            a+= arr[l] * pow(10,4-l);
            vis[arr[l]]=1;
        }
        b = a*N;
        if(ceil(log10(b)) != 5) return;
        int tmp = b;
        while(tmp){
            if(vis[tmp%10]) return;
            vis[tmp%10]=1;
            tmp/=10;
        }
        ans.push_back({b,a});

        return;
    }
    for(int j=0;j<10;j++){
        if(!vis[j]){
            vis[j]=1;
            arr[k]=j;
            solve(i+1,k+1,arr);
            vis[j]=0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

    cin>>N;
    n=5;
    memset(vis,0,sizeof(vis));
    int arr[10];
    solve(0,0,arr);

    if(ans.empty()){
        cout << "There are no solutions for N.";
        return 0;
    }
    for(auto e:ans){
        cout << e.first << " / ";
        if(ceil(log10(e.second)) == 4) cout << 0;
        cout << e.second << " = " << N << '\n';
    }
    
    return 0;
}