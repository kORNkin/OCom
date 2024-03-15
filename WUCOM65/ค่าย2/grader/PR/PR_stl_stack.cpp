#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin>>T;
    while(T--){
        int q; cin>>q;
        stack<int> st;
        while(q--){
            char c; cin>>c;
            if(c=='a'){
                int x; cin>>x;
                st.push(x);
            }else if(c=='b'){
                if(!st.empty()){
                    cout << st.top() << " ";
                    st.pop();
                }else cout << "-1 ";
            }else if(c=='c'){
                cout << st.size() << " ";
            }else {
                if(!st.empty())
                    cout << st.top() << " ";
                else cout << "-1 ";
            }
        } cout << '\n';
    }

    return 0;
}