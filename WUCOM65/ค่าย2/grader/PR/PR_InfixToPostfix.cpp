#include<bits/stdc++.h>
using namespace std;
int cal(char op){
    if(op==')') return 0;
    if(op=='(') return 0;
    if(op=='^') return 3;
    if(op=='*') return 2;
    if(op=='/') return 2;
    if(op=='+') return 1;
    if(op=='-') return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s; cin>>s;
    stack<char> st;

    int co = 0;

    for(auto c:s){
        if((c>='A' && c<='Z') || (c>='a' && c<='z'))
            cout << c;
        else {
            if(c == ')'){
                while( !st.empty() && st.top() != '('){
                    cout << st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop();
            }
            else if(st.empty() || st.top() == '(' || c=='(')
                 st.push(c);
            else {
                while(!st.empty() && cal(st.top()) >= cal(c)){
                    cout << st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }

    return 0;
}