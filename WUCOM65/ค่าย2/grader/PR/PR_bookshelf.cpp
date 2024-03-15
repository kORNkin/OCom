#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    list<int> arr;
    for(int i=0;i<n;i++) { 
        int x; cin>>x;
        arr.push_back(x);
    }
    cin>>n;
    while(n--){
        int x; cin>>x;
        int i=1;
        for(auto e:arr){
            if(i==x){
                cout << e << '\n';
                arr.remove(e);
                break;
            }
            i++;
        }
    }
        

    return 0;
}