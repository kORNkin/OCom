#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int w=1,s=0;
    pair<int,int> arr[25];
    for(int i=1;i<=24;i++){
        int tmp=w;
        w+=s+1; s=tmp;
        arr[i].first = w;
        arr[i].second = w+s+1;
    }
    int c; cin>>c;
    while(c!=-1){
        cout << arr[c].first << " " << arr[c].second << '\n';
        cin>>c;
    }
    
    return 0;
}