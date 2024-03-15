#include<bits/stdc++.h>
using namespace std;
void print(list<int> arr){
    for(auto x:arr) cout << x << ' ';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;cin>>T;
    while(T--){
        int n; cin>>n;
        list<int> arr; 
        while(n--){
            char c; cin>>c;
            int x;
            if(c=='1') {
                cin>>x; 
                arr.emplace_back(x);
                print(arr);
            }else if(c=='2'){
                arr.sort();
                print(arr);
            }else if(c=='3'){
                arr.reverse();
                print(arr);
            }else if(c=='4'){
                cout << arr.size() << " ";
            }else if(c=='5'){
                print(arr);
            }else if(c=='6'){
                arr.remove(arr.back());
                print(arr);
            }else if(c=='7'){
                arr.remove(arr.front());
                print(arr);
            }else if(c=='8'){
                cin>>x;
                arr.emplace_front(x);
                print(arr);
            }
        } cout << '\n';
    }

    return 0;
}