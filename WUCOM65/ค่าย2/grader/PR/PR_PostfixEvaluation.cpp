#include<bits/stdc++.h>
using namespace std;
int cal(int a,int b,char op){
    if(op=='+') return b+a;
    if(op=='-') return b-a;
    if(op=='*') return b*a;
    if(op=='/') return b/a;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    stack<int> st;
    string s; cin>>s;
    for(auto c:s){
        if(c=='+'||c=='-'||c=='*'||c=='/'){
            int a = st.top();
            st.pop();
            int b = st.top();

            st.pop();

            st.push(cal(a,b,c));
        }else st.push(c-'0');
    }   
    cout << st.top();


    return 0;
}