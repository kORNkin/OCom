#include<bits/stdc++.h>
using namespace std;
string pf;
string s;
void infixToPostfix(){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        char c = s[i];
        if(c>='A' && c<='Z')
            pf+=c;
        else if(st.empty()) 
            st.push(c);
        else if(c=='[') 
            st.push(c);
        else if(c==']'){
            while(st.top() != '['){
                pf+=st.top();
                st.pop();
            }
            st.pop();
        }
        else if(!st.empty() && (st.top()-'0') < (c-'0'))
            st.push(c);
        else if(!st.empty() && (st.top()-'0') >= (c-'0'))
        {
            while(!st.empty() && (st.top()-'0') >= (c-'0'))
            {
                pf+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        pf+=st.top();
        st.pop();
    }
}
int cal(int a,int b,char c){
    if(c=='1') return floor(0.04*(a+b));
    if(c=='2') return floor(0.08*(a+b));
    if(c=='3') return floor(0.16*(a+b));
}
void calPostfix(){
    stack<int> st;
    for(auto c:pf){
        if(c>='A' && c<='Z')
            st.push(20);
        else {
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();

            st.push(a+b+cal(a,b,c));
            
        }
    }
    cout << st.top();
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>s;
    infixToPostfix();
    cout << pf << '\n'; 
    calPostfix();

    return 0;
}