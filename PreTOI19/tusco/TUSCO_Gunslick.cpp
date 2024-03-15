#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long n,mx=0,c=0; cin>>n;
    vector<pair<int,int>> t;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        t.push_back({x,1});
        t.push_back({y,-1});
    }
    sort(t.begin(),t.end());
    //int i,j;
    for(auto e:t){
        c+=e.S;
        if(mx<=c){
            mx=c;
            //i=e.F;
            //j=(&e+1)->F;
        }
        
    }
    cout << mx << endl;
    //cout << i << " " << j;

    /*int n,mx=0; cin>>n;
    int arr[100001]; memset(arr,0,sizeof(arr));
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        arr[a]++;
        arr[b]--;
        //mx= max(max(arr[a],arr[b]),mx);
    }
    int cnt=0;
    for(int i=0;i<=100000;i++){
        if(arr[i]>0){
            cnt+=arr[i];
            mx=max(cnt,mx);
        }
    }
    
    cout << mx;*/

    return 0;
}
/*
5
2 6
1 3
4 8
3 8
6 7
*/