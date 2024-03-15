#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    set<char> s;
    while(n--){
        char c; cin>>c;
        s.insert(c);
    }    
    n = s.size();
    vector<char> arr;
    for(auto x:s){
        arr.push_back(x);
    }
    for(int i=1;i<=2*n;i++){
        for(int j=1;j<=4*n-1;j++){
            if(i>n&&j>=i && j<i+((2*n-i)*2+1)) cout << ' ';
            else if(i+j > 2*n && j-i < 2*n) cout << arr[(i-1)%n];
            else cout << ' ';
        } cout << '\n';
    }

    return 0;
}