#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;cin>>T;
    while(T--){
        int n; cin>>n;
        set<int> arr; 
        while(n--){
            char c; cin>>c;
            int x;
            if(c=='a') {
                cin>>x;
                arr.insert(x);
            }else if(c=='b'){
                for(auto e:arr) cout << e << ' ';
            }else if(c=='c'){
                cin>>x;
                arr.erase(x);
            }else if(c=='d'){
                cin>>x;
                if(arr.count(x)){
                    cout << "1 ";
                }else cout << "-1 ";
            }else if(c=='e'){
                cout << arr.size() << ' ';
            }
        } cout << '\n';
    }

    return 0;
}