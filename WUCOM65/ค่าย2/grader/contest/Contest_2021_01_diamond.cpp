#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin>>t;
    set<char> s;
    while(t--){
        char c; cin>>c;
        s.insert(c);
    }
    vector<char> arr;
    for(auto c:s) arr.push_back(c);
    int n = s.size(),k=0;
    bool ch=1;
    for(int i=-n+1; i<n; i++){
        for(int j=-n+1; j<n; j++){
            if(abs(j)>=i+n || -abs(j)<=i-n) cout << ' ';
            else {
                //cout << '*';
                cout << arr[k];
                if(ch) k++;
                else k--;
                if((i<=0 && k==(n+i-1)) || (i>0 && k==(n-i-1))){           
                    ch=0;
                }
            }
        } 
        k=0; ch=1;
        cout << '\n';
    }

    return 0;
}