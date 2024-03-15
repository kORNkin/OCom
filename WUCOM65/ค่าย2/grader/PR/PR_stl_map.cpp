#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;cin>>T;
    while(T--){
        int n; cin>>n;
        map<int,int> arr; 
        while(n--){
            char c; cin>>c;
            int x;
            if(c=='a') {
                int a,b; cin>>a>>b;
                arr[a]=b;
            }else if(c=='b'){
                cin>>x;
                if(arr.count(x)){
                    cout << arr[x] << ' ';
                }else cout << "-1 ";
            }else if(c=='c'){
                for(auto e:arr){
                    cout << e.first << " " << e.second << ' ';
                }
            }
        } cout << '\n';
    }

    return 0;
}