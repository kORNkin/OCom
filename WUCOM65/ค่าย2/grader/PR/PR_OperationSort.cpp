#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        string po; cin >> po;
        reverse(po.begin(), po.end());
        stack<string> st;
        for(auto c: po){
            string s;
            if(c >= 'A' && c <= 'Z') s += c;
            else {
                s += st.top(); st.pop();
                s += st.top(); st.pop();
                s.push_back(c);
            }
            st.push(s);
        }
        while(!st.empty()) cout << st.top(), st.pop();
        cout << '\n';
    }

    return 0;
}