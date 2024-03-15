#include<bits/stdc++.h>
using namespace std;

stack<bool> st;
string s;
int cnt;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    for(auto c : s){
        if(c == '('){
            st.push(1);
        }else {
            if(st.empty()) cnt++;
            else st.pop();
        }
    }
    
    cnt += st.size();
    cout << cnt;

    return 0;
}