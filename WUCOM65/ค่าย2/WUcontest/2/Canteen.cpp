#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    deque<int> arr[100001];
    int q; cin>>q;
    while(q--){
        int n; cin>>n;
        int x,y;
        if(n==1){
            cin>>x>>y;
            arr[y].push_back(x);
        }else if(n==2){
            cin>>y;
            if(!arr[y].empty())
                arr[y].pop_front();
        }else if(n==3){
            cin>>y;
            if(!arr[y].empty())
                cout << arr[y].front() << "\n";
            else cout << "-1\n";
        }else {
            cin>>y;
            cout << arr[y].size() << '\n';
        }
    }

    return 0;
}