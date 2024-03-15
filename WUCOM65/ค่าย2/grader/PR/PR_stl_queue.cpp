#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin>>T;
    while(T--){
        int Q; cin>>Q;
        queue<int> q;
        while(Q--){
            char c; cin>>c;
            if(c=='a'){
                int x; cin>>x;
                q.push(x);
            }else if(c=='b'){
                if(!q.empty()){
                    cout << q.front() << " ";
                    q.pop();
                }else cout << "-1 ";
            }else if(c=='c'){
                cout << q.size() << " ";
            }else if(c=='d'){
                if(!q.empty())
                    cout << q.front() << " ";
                else cout << "-1 ";
            }else if(c=='e'){
                if(!q.empty())
                    cout << q.back() << " ";
                else cout << "-1 ";
            }
        } cout << '\n';
    }

    return 0;
}